#include <cstdio>
#include <cstdlib>
#include <cstring>

unsigned int prediction[16384];
unsigned int pre, mis, branch, address;
int m, n;
char *trace, c;

void bimodal(int add_bit){
	int i;
	for(i=0; i<(1<<add_bit); i++)
		prediction[i]=2;

	while(scanf("%x %c", &address, &c)!=EOF) {
		pre++, branch=0, address>>=2;
		for(i=0; i<add_bit; i++)
			branch = branch + (address&(1<<i));

		if(prediction[branch] > 1 && c!='t')
			mis++;
		else if(prediction[branch] < 2 && c=='t')
			mis++;

		if(c=='t') {
			if(prediction[branch] != 3)
				prediction[branch]++;
		}
		else {
			if(prediction[branch] != 0)
				prediction[branch]--;
		}
	}
}

void gshare(int add_bit, int bhr_bit){
	int i, bhr=0;
	for(i=0; i<(1<<add_bit); i++)
		prediction[i]=2;

	while(scanf("%x %c", &address, &c)!=EOF) {
		pre++, branch=0, address>>=2;
		for(i=0; i<add_bit; i++)
			branch = branch + (address&(1<<i));
		branch = branch ^ (bhr << (add_bit - bhr_bit));

		if(prediction[branch] > 1 && c!='t')
			mis++;
		else if(prediction[branch] < 2 && c=='t')
			mis++;

		if(c=='t') {
			if(prediction[branch] != 3)
				prediction[branch]++;
			bhr = (bhr>>1) | (1<<(bhr_bit-1));
		}
		else {
			if(prediction[branch] != 0)
				prediction[branch]--;
			bhr >>= 1;
		}
	}
}

int main(int argc, char *argv[]) {
	if(argc<5) {
		printf("Usage: ./sim bimodal [M2] 0 0 <trace_file>\n");
		printf("Usage: ./sim gshare [M1] [N] 0 0 <trace_file>\n");
		return 0;
	}
	pre=0, mis=0;
	puts("COMMAND");

	if (!strcmp(argv[1], "bimodal")) {
		if(!freopen(argv[5], "r", stdin))
			return 0;
		trace = argv[5];
		m=atoi(argv[2]);
		int i, len=(int)strlen(trace);
		for(i=len; i>=0; i--)
			if(trace[i]=='/')
				break;
		trace=trace+i+1;
		bimodal(m);
		printf("./sim bimodal %d 0 0 %s\n", m, trace);
	}

	else if (!strcmp(argv[1], "gshare")) {
		if(!freopen(argv[6], "r", stdin))
			return 0;
		trace = argv[6];
		m=atoi(argv[2]), n=atoi(argv[3]);
		int i, len=(int)strlen(trace);
		for(i=len; i>=0; i--)
			if(trace[i]=='/')
				break;
		trace=trace+i+1;
		gshare(m, n);
		printf("./sim gshare %d %d 0 0 %s\n", m, n, trace);
	}

	puts("OUTPUT");
	printf("number of predictions:\t%d\n", pre);
	printf("number of mispredictions:\t%d\n", mis);
	printf("misprediction rate:\t%0.2f%%\n", 100.0*mis/pre);
	puts(strcmp(argv[1], "gshare")?"FINAL BIMODAL CONTENTS":"FINAL GSHARE CONTENTS");
	for(int i=0; i<(1<<m); i++)
		printf("%d\t%d\n", i, prediction[i]);

	return 0;
}