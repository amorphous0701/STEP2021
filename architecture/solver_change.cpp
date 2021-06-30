#include <bits/stdc++.h>
using namespace std;
using cor = pair<double, double>;

int64_t min_dist_city(unordered_set<int64_t>& unvisited_cities, vector<vector<double>>& city_dis, int64_t current_city)
{
    double min_dis = 10000000000000;
    int64_t min_city;
    for (auto city : unvisited_cities) {
        if (min_dis > city_dis[city][current_city]) {
            min_city = city;
            min_dis = city_dis[city][current_city];
        }
    }
    unvisited_cities.erase(min_city);
    return min_city;
}

double distance(cor city1, cor city2)
{
    return sqrt(pow(city1.first - city2.first, 2) + pow(city1.second - city2.second, 2));
}

vector<string> split(string& input, char delimiter)
{
    istringstream stream(input);
    string field;
    vector<string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

void read_csv(vector<cor>& city_cor, int index)
{
    string url = "./input/input_" + to_string(index) + ".csv";
    ifstream ifs(url);
    string line;
    int i = 0;
    while (getline(ifs, line)) {
        vector<string> strvec = split(line, ',');
        if (strvec[0] == "x")
            continue;
        city_cor.push_back({stod(strvec[0]), stod(strvec[1])});
        i++;
    }
}

void write_csv(vector<int64_t> tour, int index)
{
    string url = "./output/best_greedy_" + to_string(index) + ".csv";
    ofstream ofs(url);
    ofs << "index" <<endl;
    for (int i = 0; i < tour.size(); i++) {
        ofs << tour[i] << endl;
    }
}

double tour_dist(vector<int64_t> &tour,vector<vector<double>> &city_dis){
    double route=0;
    for(int i=0;i<tour.size();i++){
        city_dis[tour[i]][tour[(i+1)%tour.size()]];
    }
    return route;
}

int main()
{
    for (int challenge = 0; challenge < 8; challenge++) {
        cout<<"Now on challenge"<<challenge<<endl;
        vector<cor> city_cor;
        read_csv(city_cor, challenge);
        int64_t N = city_cor.size();

        vector<vector<double>> city_dis(N, vector<double>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                city_dis[i][j] = city_dis[j][i] = distance(city_cor[i], city_cor[j]);
            }
        }

        vector<int64_t> min_tour;
        double min_dist=100000000000;

        for(int start=0;start<N;start++){
            unordered_set<int64_t> unvisited_cities;
            for (int i = 0; i < N; i++){
                unvisited_cities.insert(i);
            }

            vector<int64_t> tour;
            int64_t current_city = start;
            unvisited_cities.erase(current_city);
            tour.push_back(current_city);

            while (unvisited_cities.size()) {
                int64_t next_city = min_dist_city(unvisited_cities, city_dis, current_city);
                tour.push_back(next_city);
                current_city = next_city;
            }

            double now_dist=tour_dist(tour,city_dis);

            if(now_dist<min_dist){
                min_tour=tour;
                min_dist=now_dist;
            }
        }

        write_csv(min_tour, challenge);
    }
}