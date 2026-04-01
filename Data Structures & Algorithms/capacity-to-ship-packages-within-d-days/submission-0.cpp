class Solution {
public:
        bool canShip(int mid, int days, vector<int>& weights) {
            int cap = mid;
            int ship = 1;
            for (int w : weights) {
                if (cap - w < 0) {
                    ship++;
                    if (ship > days) return false;
                    cap = mid;
                }
                cap -= w;
            }
            return true;
        }
        int shipWithinDays(vector<int>& weights, int days) {
            int l = *max_element(weights.begin(), weights.end());
            int r = accumulate(weights.begin(), weights.end(), 0);
            int res = r;
            while (l <= r) {
                int m = l + (r - l) / 2;
                int count = 1;
                int sum = 0;
                for (int w : weights) {
                    if (sum + w > m) {
                        count++;
                        sum = 0;
                    }
                    sum += w;
                }
                if (count <= days) {
                    res = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            return res;
        }
    };