#include<bits/stdc++.h>
using namespace std;


// Time complexity: O(n)
int bestTimeToBuyAndSellStock_1(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0; // Handle edge case

    int buy = prices[0]; // Initialize buy price to the first day's price
    int maxProfit = 0; // Initialize maxProfit to 0

    // Iterate through each day's price starting from the second day
    for (int i = 1; i < n; ++i) {
        // If the current day's price is less than the buy price, update the buy price
        if (prices[i] < buy) {
            buy = prices[i];
        } else { // Otherwise, calculate the profit if we sell on this day
            maxProfit = max(maxProfit, prices[i] - buy);
        }
    }

    return maxProfit;
}


// Time complexity: O(n)
int bestTimeToBuyAndSellStock_2(vector<int>&prices) {
    int n = prices.size();

    int buy = prices[0];
    int maxProfit = 0; 

    for (int i = 1; i < n; ++i) {
        int cost=prices[i]-buy;
        maxProfit=max(maxProfit,cost);
        buy=min(buy,prices[i]);
    }

    return maxProfit;
}


int main(){
     int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    return 0;
}