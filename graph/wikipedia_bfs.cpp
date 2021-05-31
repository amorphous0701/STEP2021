#include <bits/stdc++.h>
using namespace std;
using Pair=pair<string,int>;

void find_route(string to, map<string, set<string>> links, vector<string> check, queue<Pair> que)
{
    while (!que.empty()) {
        Pair top = que.front();
        string top_name = top.first;
        int top_index = top.second;

        que.pop();
        check.push_back(top_name);

        if (top_name == to) {
            cout << top_index<<endl;
            return ;
        }

        for (auto i = links[top_name].begin(); i != links[top_name].end(); i++) {
            if (find(check.begin(), check.end(), *i) == check.end()) {
                que.push({*i,top_index+1});
            }
        }
    }
    cout<<"NOT FOUND"<<endl;
    
}

string name_to_number(string name, map<string, string> pages)
{
    if (pages.find(name) != pages.end()) {
        return pages[name];
    }
    return "";
}

void read_pages(map<string, string>& pages, string path)
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

void read_links(map<string, set<string>>& links, string path)
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

int main()
{
    map<string, string> pages;
    map<string, set<string>> links;
    vector<string> check;
    queue<Pair> bfs_que;

    read_pages(pages, "data/pages.txt");
    read_links(links, "data/links.txt");

    string from = "Google";
    string to = "渋谷";
    string from_number = name_to_number(from, pages);
    string to_number = name_to_number(to, pages);
    bfs_que.push({from_number,0});
    find_route(to_number, links, check, bfs_que);

    return 0;
}