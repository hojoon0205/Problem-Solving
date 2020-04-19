#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ALL(x) (x).begin(), (x).end()

struct datum{
    bool is_vertical;
    int n;
    set<string> tags;
};

vector<datum> data;
vector<bool> check;

int N;

void read_dataset(char c) {
    string input = "data/";
    input += c;
    input += ".txt";
    freopen(input.c_str(), "r", stdin);
    cin >> N;
    int n = N;
    check.resize(N);
    while (n--) {
        string s; cin >> s;
        int t; cin >> t;
        set<string> tags;
        while (t--) {
            string tag; cin >> tag;
            tags.insert(tag);
        }
        data.push_back({s == "V", t, tags});
    }
}
vector<int> parse(string line) {
    vector<int> ret;
    istringstream is(line);
    int n;
    while (is >> n) {
        ret.push_back(n);
        assert(!check[n]);
        check[n] = true;
    }
    if (ret.size() == 1) {
        assert(!data[ret[0]].is_vertical);
    } else if (ret.size() == 2) {
        assert(data[ret[0]].is_vertical && data[ret[1]].is_vertical);
    } else {
        assert(ret.size() == 2 || ret.size() == 1);
    }
    return ret;    
}

int calc(vector<int>& slide1, vector<int>& slide2) {
    set<string> s1, s2;
    for (auto kk : slide1) {
        s1.insert(ALL(data[kk].tags));
    }
    for (auto kk : slide2) {
        s2.insert(ALL(data[kk].tags));
    }
    int sz = 0;
    for (auto element : s1) {
        if (s2.count(element))
            ++sz;
    }
    int a = (int)s1.size() - sz;
    int b = sz;
    int c = (int)s2.size() - sz;
    return min({a, b, c});
}
int solve() {
    char dataset; cin >> dataset;
    string input_file_name; cin >> input_file_name; // "my_anwer.txt"
    read_dataset(dataset);
    freopen(input_file_name.c_str(), "r", stdin);
    int N; cin >> N;
    string prev, now;
    getline(cin, prev); // flush
    getline(cin, prev);
    long long ans = 0;
    vector<int> slide1 = parse(prev);
    for (int i = 1; i < N; i++) {
        getline(cin, now);
        vector<int> slide2 = parse(now);
        ans += calc(slide1, slide2);
        slide1 = slide2;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve();
}