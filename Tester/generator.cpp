#include<bits/stdc++.h>
using namespace std;

int random(int a,int b){
	return a + rand()%(b-a+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27};
    int prr[10]; 

    prr[0] = 1;
    for (int i=1; i<10; i++)
        prr[i] = prr[i-1] * arr[i-1];

    srand(time(nullptr));

    int n = random(1, 10);
    cout << "1\n" << n << "\n";

    for (int i=0; i<n; i++)
    	cout << prr[random(0, 9)] << " ";
    cout << "\n";

    for (int i=2; i<=n; i++)
        cout << random(1, i-1) << " " << i << "\n";

	return 0;
}