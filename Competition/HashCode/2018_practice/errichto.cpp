// Warsaw Rhubarbs
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dist(const pair<int,int> & a, const pair<int,int> & b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

struct Ride {
    pair<int,int> start, end;
    int when_start, when_end;
    int id;
    void read(int _id) {
        id = _id;
        cin >> start.first >> start.second >> end.first >> end.second;
        cin >> when_start >> when_end;
    }
    int length() const {
        return dist(start, end);
    }
};

int bonus_start;

vector<vector<int>> output;
int super;
struct Car {
    pair<int,int> where;
    int when;
    int id;
    int when_can_get(const pair<int,int> & a) const {
        return when + dist(where, a);
    }
    int real_simulate(const Ride & ride, bool indeed) {
        ll score = 0;
        when += dist(where, ride.start);
        if(when <= ride.when_start) {
            if(indeed) ++super;
            when = ride.when_start;
            score += bonus_start;
        }
        when += ride.length();
        if(when <= ride.when_end) {
            score += ride.length();
        }
        else {
            assert(!indeed);
            score = 0;
        }
        where = ride.end;
        return score;
    }
    int fake_simulate(const Ride & ride) const {
        Car x = *this;
        return x.real_simulate(ride, false);
    }
    int would_wait(const Ride & ride) const {
        int get_there = when_can_get(ride.start);
        return max(0, ride.when_start - get_there);
    }
    int would_need(const Ride & ride) const {
        return max(when_can_get(ride.start), ride.when_start) - when;
    }
    void add_ride(const Ride & ride) const {
        output[id].push_back(ride.id);
    }
};


int main() {
    int h, w, cnt_cars, cnt_rides;
    int T;
    cin >> h >> w >> cnt_cars >> cnt_rides >> bonus_start >> T;
    output.resize(cnt_cars);
    
    vector<Ride> rides(cnt_rides);
    for(int i = 0; i < cnt_rides; ++i)
        rides[i].read(i);
    
    vector<Car> cars(cnt_cars);
    for(int i = 0; i < cnt_cars; ++i)
        cars[i].id = i;
        
    vector<bool> done(cnt_rides);
    
    int total_score = 0;
    int AC = 0;
    
    vector<int> far(cnt_rides, INT_MAX);
    for(int i = 0; i < cnt_rides; ++i) if(!done[i])
        for(int j = 0; j < cnt_rides; ++j) if(i != j) if(!done[j])
            far[i] = min(far[i], dist(rides[i].end, rides[j].start));
    
    while(true) {
        bool anything = false;
        
        for(Car & car : cars) {
            pair<int, int> best;
            best.first = INT_MAX;
            for(int i = 0; i < cnt_rides; ++i) if(!done[i]) {
                int would_score = car.fake_simulate(rides[i]);
                if(would_score == 0) continue; // can't do it in time
                int wasted = car.would_need(rides[i]);
                int when_would_finish = car.when + wasted + rides[i].length();
                if(when_would_finish <= T * 0.98) wasted += far[i] / 15;
                best = min(best, {wasted, i});
            }
            if(best.first == INT_MAX) continue;
            int i = best.second;
            done[i] = true;
            int tmp = car.real_simulate(rides[i], true);
            total_score += tmp;
            anything = true;
            car.add_ride(rides[i]);
            ++AC;
        }
        if(!anything) break;
    }
    cerr << super << "/" << AC << "/" << cnt_rides << "\n";
    cerr << "score = " << total_score / 1e6 << "\n";
    for(int i = 0; i < cnt_cars; ++i) {
        printf("%d", (int) output[i].size());
        for(int x : output[i]) printf(" %d", x);
        puts("");
    }
}
