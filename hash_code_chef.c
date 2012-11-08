/*
Problem Statement:

Chef Ash and Chef Elsh invented a new hash function! Their hash function will map a binary string consisting of characters 'A' and 'E' into an integer called the hash value of the string.
The pseudocode of the hash function is as below. hash(S) is the hash value of a binary string S. |S| denotes the length of S.
function hash(S):
	result = number of characters 'A' in S
	if |S| > 1:
		(S1, S2) = split(S)
		result = result + max(hash(S1), hash(S2))
	end if
	return result
end function
The function split in the above pseudocode takes a binary string S as the parameter and returns a pair of binary strings (S1, S2) such that:
|S1| <= |S2|.
The difference of |S1| and |S2| is at most 1.
The concatenation of S1 and S2 (in that order) is S.
For example, split("AAAEE") returns ("AA", "AEE"), whereas split("AEAEAE") returns ("AEA", "EAE").
You doubt that this hash function have good distribution of different hash values. So, you wonder how many different binary strings consisting of A 'A' characters and E 'E' characters that have hash value of V.
Input

The first line contains a single integer T, the number of test cases. T test cases follow. Each testcase consists of a single line consisting of three integers A, E, and V.
Output

For each test case, output a single line consisting the number of different binary strings satisfying the rule, modulo 1000000007.
Constraints

1 ≤ T ≤ 1000
0 ≤ A ≤ 50
0 ≤ E ≤ 50
0 ≤ V ≤ 1000
Example

Input:
4
0 0 0
1 0 1
3 2 6
4 2 8

Output:
1
1
3
4
Explanation

For the last test case, the solutions are:
AAEAAE
AEAAAE
AAEAEA
AEAAEA
*/
#ifdef MYCODE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
    printf("Hello World:\n");
    char *s = "AEEAEEA";
    int n = hash(s,0,strlen(s)-1);
    printf("The hash key = %d\n",n);
    return 0;
}
int max(int a,int b){
    return (a>b?a:b);
}

int count(char *S, char a, int st, int end){
    int num = 0;
    int i;
    for(i=st;i<=end;i++){
        if(S[i]==a){
            num++;
        }
    }
    return num;
}

int hash(char* S,int st, int end){
    int result = count(S,'A',st,end);
    int len = end -st;
    if(len >1){
        result = result + max(hash(S,st,(st+end)/2 -1 ),hash(S,(st+end)/2,end));
    }
    return result;
}

#endif
#ifndef MYCODE

#include<stdio.h>
#include<string.h>
#define LL long long
#define M 1000000007
LL dp[60][60][160];

LL S(int a,int e,int v)
{
int m=(a+e)/2,i;
LL p=0;
if(v<0||~dp[a][e][v]||a+e<=1)return(v<0)?0:((~dp[a][e][v])?dp[a][e][v]:(dp[a][e][v]=(a<=v)));
for(i=-1;++i<=m;p=(i<=a&&m-i<=e)?(p+S(i,m-i,v-a)*S(a-i,e-(m-i),v-a))%M:p);
return dp[a][e][v]=p;
}

main()
{
int f,a,e,v;
LL r;
for(scanf("%d",&f)&&memset(dp,-1,sizeof dp);f--;scanf("%d%d%d",&a,&e,&v),printf("%lld\n",(r=v>152?0:(r=(S(a,e,v)-S(a,e,v-1))%M)<0?r+M:r)));
return 0;
}

#endif
