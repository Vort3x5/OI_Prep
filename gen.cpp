#include <cstdio>
#include <algorithm>
using namespace std;
const long long ma=1000, mi=1000000000;
int tb[ma + 10];
long long R(long long a, long long b) {
    return a+rand()%(b-a+1);
}
int main(int argc, char *argv[])
{
   srand(atoi(argv[1]));
   int n=R(1, ma), q=R(1, ma),a, b, t;
   printf("%d %d\n", n, q);
    int zero_per = R(2, 10);
	for(int i = 1; i <= n ; i++)
	{
        tb[i] = R(1, ma);
        if(tb[i] % zero_per == 0)tb[i] = 0;
		printf("%lld\n", tb[i]);
	}
	while(q--)
	{
        t = R(0,1);
        if(t==0) {
            a=R(1, n);
            tb[a] = R(1, ma);
            if(tb[a] % zero_per == 0)tb[a] = 0;
            printf("%d %d\n", a, tb[a]);
        }
        else {
            a=R(1, n);
            b=R(a,n);
            int il = 0;
            for(int i = a; i <= b; i++)
                il += !tb[i];
           
            if(il > 0)printf("%d %lld\n", a, b, R(1, il));
            else q++;
        }
	}
}

