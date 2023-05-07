#include<bits/stdc++.h>
using ll = long long int;
using namespace std;

ll getMedian(vector<ll> arr,  int l, int r) {
	vector<int> subarr;
	while(l <= r) {
	 subarr.push_back(arr[l]);
	 ++l;
	}
	
	sort(subarr.begin(), subarr.end());
	int n = subarr.size();
	return subarr[n / 2];
}

ll medianGame(vector<ll> arr, int N){
	// taking moves
	for(int moves = 1; moves <= N-2 && arr.size() > 2; ++moves) {
		ll minMed = LLONG_MAX;
		int n = arr.size();
		// forminng subarrays
		for (int st = 0; st <= n-3; ++st) {
			for(int ed = st + 2; ed < n; ed += 2) {
				//cout << st <<" : " << ed <<"\n";
				minMed = min(minMed, 
					getMedian(arr, st, ed)
				);
			}
		}
		//delete first occurrence of 
		vector<ll> newArr;
		bool isDeleted = false;
		for(int i = 0;i < n;++i) {
			if(arr[i] == minMed && !isDeleted) {
				isDeleted = true;
			} else {
				newArr.push_back(arr[i]);
			}
		}
		arr = newArr;
	}
	ll sum = 0;
	for(ll v : arr) sum += v;
	return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int n;
        cin >> n;
		vector<ll> arr(n);
		for(int i = 0;i < n;++i)
			cin >> arr[i];
        int out_;
        out_ = medianGame(arr, n);
        cout << out_;
        cout << "\n";
    }
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int getMedian(int a[], int i, int n){
// 	sort(a + i, a + n);
// 	if(n % 2 != 0)
// 		return a[n/2];
// 	else
// 		return (a[(n - 1) / 2] + a[n / 2]) / 2;
// }

// int deleteElement(int arr[], int n, int x){
// // Search x in array
// 	int i;
// 	for (i=0; i<n; i++)
//     	if (arr[i] == x)
//         	break; 
// // If x found in array   q
// 	if (i < n){
// 		n = n - 1;
//     	for (int j=i; j<n; j++)
//         	arr[j] = arr[j+1];
// 	}
// 	return n;
// }

// int medianGame(int arr[], int n){
// 	int slow = 0, fast = 0, remove ;
// 	int i = 1;
// 	while(n > 3){
// 		slow = getMedian(arr, i, i + 2);
// 		fast = getMedian(arr, i+1, i+1+2);
// 		remove = min(slow, fast);
// 		n = deleteElement(arr, n, remove);
// 	}
// 	// n = deleteElement(arr, n, remove);

// 	if(n <= 3){
// 		slow = getMedian(arr, i, i + 2);
// 		n = deleteElement(arr, n, slow);
// 	}

//     cout << arr[1] << " " << arr[2] << endl;

// 	return arr[1]+arr[2];
// }

// int main() {
//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     // int T;
//     // cin >> T;
//     // for(int t_i = 0; t_i < T; t_i++)
//     // {
//         cout << "Enter Range : ";
//         int n;
//         cin >> n;
//         int arr[n];
//         cout << "\nEnter Element of Array : " << endl;
// 		for(int i = 1; i <= n; i++){
//         	cin >> arr[i];
// 		}
//         int out_;
//         out_ = medianGame(arr, n);
//         cout << "Result : "<< out_ ;
//         cout << "\n";
//     // }
//     return 0;
// }