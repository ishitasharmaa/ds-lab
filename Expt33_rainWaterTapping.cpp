#include <iostream>
#include <vector>

using namespace std;

int trapRainwater(vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
        return 0; // You need at least three bars to trap rainwater.
    }

    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int trappedWater = 0;
    for (int i = 1; i < n - 1; i++) {
        trappedWater += min(leftMax[i], rightMax[i]) - height[i];
    }

    return trappedWater;
}

int main() {
    vector<int> height;
    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(2);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);

    int trappedWater = trapRainwater(height);
    cout << "Trapped rainwater: " << trappedWater << " units" << endl;

    return 0;
}
