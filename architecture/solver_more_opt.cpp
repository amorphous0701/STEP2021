#include <bits/stdc++.h>
using namespace std;
using cor = pair<double, double>;

vector<int64_t> perform_two_opt(vector<int64_t> tour,vector<vector<double>> &city_dis,int64_t N){ //二つの経路入れ替えた方が短ければ入れ替える！
    while(true){
        bool complete=true;
        for(int i=0;i<N-2;i++){
            for(int j=i+2;j<N;j++){
                if(i==0&&j==N-1) continue;
                if(city_dis[tour[i]][tour[i+1]]+city_dis[tour[j]][tour[(j+1)%N]] >
                city_dis[tour[i]][tour[j]]+ city_dis[tour[i+1]][tour[(j+1)%N]] ){
                    vector<int64_t> new_tour=tour;
                    for(int change=0;change<j-i;change++){
                        new_tour[i+1+change]=tour[j-change];
                    }
                    tour=new_tour;
                    complete=false;
                }
            }
        }
        if(complete) break;
    }
    return tour;
}

vector<int64_t> perform_one_or_opt(vector<int64_t> tour,vector<vector<double>> &city_dis,int64_t N){ //二つの経路入れ替えた方が短ければ入れ替える2！
    while(true){
        bool complete=true;
        for(int i=0;i<N-3;i++){
            for(int j=i+3;j<N;j++){
                if(i==0&&j==N-1) continue;
                if(city_dis[tour[i]][tour[i+1]]+city_dis[tour[i+1]][tour[i+2]]+city_dis[tour[j]][tour[(j+1)%N]] >
                city_dis[tour[i]][tour[i+2]]+ city_dis[tour[j]][tour[i+1]]+city_dis[tour[i+1]][tour[(j+1)%N]]){
                    vector<int64_t> new_tour(N);
                    if(j==N-1){
                        for(int index=0;index<i+1;index++) new_tour[index]=tour[index];
                        for(int index=i+1;index<N-1;index++) new_tour[index]=tour[index+1];
                        new_tour[N-1]=tour[i+1];
                    }else{
                        for(int index=0;index<i+1;index++) new_tour[index]=tour[index];
                        for(int index=i+1;index<j;index++) new_tour[index]=tour[index+1];
                        new_tour[j]=tour[i+1];
                        for(int index=j+1;index<N;index++) new_tour[index]=tour[index];
                    }
                    tour=new_tour;
                    complete=false;
                }
            }
        }
        if(complete) break;
    }
    return tour;
}

vector<int64_t> move_subsequence(vector<int64_t> tour,vector<vector<double>> &city_dis,int64_t N,int64_t space){ //二つの経路入れ替えた方が短ければ入れ替える3！
    for(int i=0;i<10;i++){
        bool complete=true;
        for(int i=0;i<N-2;i++){
            for(int j=i+2;j<N-space-1;j++){
                if(city_dis[tour[j]][tour[j+1]]+city_dis[tour[j+space]][tour[j+space+1]]+city_did[tour[i]][tour[i+1]] >
                city_dis[tour[i]][tour[j+space]]+ city_dis[tour[j+1]][tour[i+1]]+city_dis[tour[j]][tour[j+space+1]]){
                    vector<int64_t> new_tour;
                    for(int index=0;index<i+1;index++) new_tour.push_back(tour[index]);
                    for(int index=j+space;index>j;index--) new_tour.push_back(tour[index]);
                    for(int index=i+1;index<j+1;index++) new_tour.push_back(tour[index]);
                    for(int index=j+space+1;index<N;index++) new_tour.push_back(tour[index]);
                    //cout<<i<<" "<<j<<endl;
                    tour=new_tour;
                    complete=false;
                }
            }
        }
        //for(int index=0;index<N;index++) cout<<tour[index];
        //            cout<<endl;
        if(complete) break;
    }
    return tour;
}

int64_t min_dist_city(unordered_set<int64_t>& unvisited_cities, vector<vector<double>>& city_dis, int64_t current_city) //指定された町から探索されていないうち最も近くにある町の番号を返す
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

double distance(cor city1, cor city2) //二つの町の距離を返す
{
    return sqrt(pow(city1.first - city2.first, 2) + pow(city1.second - city2.second, 2));
}

vector<string> split(string& input, char delimiter) //データ読み込み時(read_csv内)で使う
{
    istringstream stream(input);
    string field;
    vector<string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

void read_csv(vector<cor>& city_cor, int index) //csvを読み込む
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

void write_csv(vector<int64_t> tour, int index) //csvに書き込む
{
    string url = "./output/more_opt_" + to_string(index) + ".csv";
    ofstream ofs(url);
    ofs << "index" <<endl;
    for (int i = 0; i < tour.size(); i++) {
        ofs << tour[i] << endl;
    }
}

double tour_dist(vector<int64_t> &tour,vector<vector<double>> &city_dis){ //経路の総和を返す。
    double route=0;
    for(int i=0;i<tour.size();i++){
        city_dis[tour[i]][tour[(i+1)%tour.size()]];
    }
    return route;
}

void set_dis(vector<vector<double>> &city_dis,vector<cor> city_cor,int64_t N){
    for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                city_dis[i][j] = city_dis[j][i] = distance(city_cor[i], city_cor[j]);
            }
    }
}

int main()
{
    for (int challenge = 0; challenge < 8; challenge++) {
        cout<<"Now on challenge"<<challenge<<endl;
        vector<cor> city_cor;
        read_csv(city_cor, challenge); //csv読み込み
        int64_t N = city_cor.size();

        vector<vector<double>> city_dis(N, vector<double>(N)); //町同士の距離を記録する配列
        set_dis(city_dis,city_cor,N); //配列に値を記録

        vector<int64_t> min_tour; //最短のルート
        double min_dist=100000000000; //最短ルート時の総距離

        for(int start=0;start<N;start++){ //スタート地点を全探索

            //greedyする前の処理
            unordered_set<int64_t> unvisited_cities; 
            for (int i = 0; i < N; i++) unvisited_cities.insert(i);

            vector<int64_t> tour;
            int64_t current_city = start;
            unvisited_cities.erase(current_city);
            tour.push_back(current_city);
            //処理終了

            while (unvisited_cities.size()) { //greedyな経路を記録
                int64_t next_city = min_dist_city(unvisited_cities, city_dis, current_city);
                tour.push_back(next_city);
                current_city = next_city;
            }

            tour=perform_two_opt(tour,city_dis,N); //two-optで短くしていく。
            tour=perform_one_or_opt(tour,city_dis,N); //one-or-optで短くしていく。
            tour=move_subsequence(tour,city_dis,N,4);

            double now_dist=tour_dist(tour,city_dis); //総距離を計算

            if(now_dist<min_dist){ //もし総距離が現時点最短総距離よりも短ければ、最短記録更新！
                min_tour=tour;
                min_dist=now_dist;
            }
        }

        write_csv(min_tour, challenge); //結果をcsvに書き込む
    }
}