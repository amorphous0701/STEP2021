#include <bits/stdc++.h>
using namespace std;

bool find_route(string from,string to,map<string,set<string>> links,vector<string> check){
    if(from==to){
        return true;
    }
    if(find(check.begin(),check.end(),from)!=check.end()){
        return false;
    }

    check.push_back(from);

    for(auto i=links[from].begin();i!=links[from].end();i++){
        if(find_route(*i,to,links,check)){
            return true;
        }
    }
    return false;
}

string name_to_number(string name,map<string,string> pages){
   if(pages.find(name)!=pages.end()){
       return pages[name];
   }
   return "";
}

void read_pages(map<string,string> &pages,string path){
    ifstream page_file(path);
    string f_data;
    while (std::getline(page_file, f_data)) {
        auto index = f_data.find('\t');
        auto title = f_data.substr(0, index);
        auto id = f_data.substr(index + 1, f_data.size() - title.size() - 1);
        pages[id] = title;
    }
}

void read_links(map<string,set<string>> &links,string path){
    ifstream link_file(path);
    string l_data;
    while (std::getline(link_file, l_data)) {
      auto index = l_data.find('\t');
      auto from = l_data.substr(0, index);
      auto to = l_data.substr(index + 1, l_data.size() - from.size() - 1);
      links[from].insert(to);
    }
}

int main(){
    map<string,string> pages;
    map<string,set<string>> links;
    vector<string> check;

    read_pages(pages,"data/pages_small.txt");
    read_links(links,"data/links_small.txt");

    string from="Google";
    string to="環境";
    //cin>>from>>to;
    string from_number=name_to_number(from,pages);
    string to_number = name_to_number(to,pages);
    if(find_route(from_number,to_number,links,check)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

  return 0;
}