#include <bits/stdc++.h>
using namespace std;
using Tuple = tuple<string, int, vector<string>>;

void read_pages(map<string, string>& pages, string path)  //pathのデータをpagesに収納
{
    ifstream page_file(path);
    string f_data;
    while (std::getline(page_file, f_data)) {
        auto index = f_data.find('\t');
        auto title = f_data.substr(0, index);
        auto id = f_data.substr(index + 1, f_data.size() - title.size() - 1);
        pages[id] = title;
    }
}

void read_links(map<string, set<string>>& links, string path)  //pathのデータをlinksに収納
{
    ifstream link_file(path);
    string l_data;
    while (std::getline(link_file, l_data)) {
        auto index = l_data.find('\t');
        auto from = l_data.substr(0, index);
        auto to = l_data.substr(index + 1, l_data.size() - from.size() - 1);
        links[from].insert(to);
    }
}

string name_to_number(string name, map<string, string> pages)  //pagesを用いてnameに対応するIDを返す
{
    if (pages.find(name) != pages.end()) {
        return pages[name];
    }
    return "";
}

vector<string> find_route(string to, map<string, set<string>> links, vector<string> check, queue<Tuple> que)  //toまでの経路探索。経路を返す。
{
    while (!que.empty()) {
        Tuple top = que.front();
        string top_name = get<0>(top);
        int top_index = get<1>(top);
        vector<string> top_path = get<2>(top);

        que.pop();
        check.push_back(top_name);
        top_path.push_back(top_name);

        if (top_name == to) {
            cout << "移動回数は" << top_index << "です。" << endl;
            return top_path;
        }

        for (auto i = links[top_name].begin(); i != links[top_name].end(); i++) {
            if (find(check.begin(), check.end(), *i) == check.end()) {
                que.push({*i, top_index + 1, top_path});
            }
        }
    }
    cout << "NOT FOUND" << endl;
    return {""};
}

void show(vector<string> path)
{  //経路を表示。
    cout << "たどった経路は" << endl;
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << endl;
    }
    cout << "です。" << endl;
}

int main()
{
    map<string, string> pages;
    map<string, set<string>> links;
    vector<string> check;
    queue<Tuple> bfs_que;

    read_pages(pages, "data/pages.txt");
    read_links(links, "data/links.txt");

    string from = "Google";
    string to = "渋谷";
    string from_number = name_to_number(from, pages);
    string to_number = name_to_number(to, pages);
    bfs_que.push({from_number, 0, {}});  //スタート地点はあらかじめキューにセットしておく。
    vector<string> path = find_route(to_number, links, check, bfs_que);
    show(path);

    return 0;
}