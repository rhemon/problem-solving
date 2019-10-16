#include<stdio.h>
#include<iostream>
#include<algorithm>

#define MAX 5842

using namespace std;

long long HN[MAX+10];

void generateHumbleNumbers(void){
    HN[1] = 1;
    int j=2;
    int w = 1, x = 1, y = 1, z = 1;

    for(long long i=2; i<=MAX; i++){
        HN[i] = min(min(2*HN[w], 3*HN[x]), min(5*HN[y], 7*HN[z]));

        if(HN[i] == 2*HN[w]) w++;
        if(HN[i] == 3*HN[x]) x++;
        if(HN[i] == 5*HN[y]) y++;
        if(HN[i] == 7*HN[z]) z++;
    }
}

int main(int argc, char** argv)
{
    generateHumbleNumbers();

    int N;

    while(cin>>N){
        if(N==0) break;

        if(N%100>10 && N%100<20){
            cout<<"The "<<N<<"th humble number is "<<HN[N]<<"."<<endl;
        }
        else if(N%10 == 1){
            cout<<"The "<<N<<"st humble number is "<<HN[N]<<"."<<endl;
        }
        else if(N%10 == 2){
            cout<<"The "<<N<<"nd humble number is "<<HN[N]<<"."<<endl;
        }
        else if(N%10 == 3){
            cout<<"The "<<N<<"rd humble number is "<<HN[N]<<"."<<endl;
        }
        else{
            cout<<"The "<<N<<"th humble number is "<<HN[N]<<"."<<endl;
        }
    }

	return 0;
}
