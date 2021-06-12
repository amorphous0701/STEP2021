#!/usr/bin/env python3

import sys
import math

from common import print_tour, read_input


def distance(city1, city2):
    return math.sqrt((city1[0] - city2[0]) ** 2 + (city1[1] - city2[1]) ** 2)

#最短経路を返す関数
def solve(cities):
    N = len(cities)

    dist = [[0] * N for i in range(N)]
    for i in range(N):
        for j in range(i, N):
            dist[i][j] = dist[j][i] = distance(cities[i], cities[j])

    current_city = 0
    unvisited_cities = set(range(1, N))
    tour = [current_city]

    while unvisited_cities:
        next_city = min(unvisited_cities,
                        key=lambda city: dist[current_city][city])
        unvisited_cities.remove(next_city)
        tour.append(next_city)
        current_city = next_city


    #二つの経路入れ替えた方が短ければ入れ替える！
    while True:
        count=0
        for i in range(N-2):
            for j in range(i+2,N):
                if dist[tour[i]][tour[i+1]]+dist[tour[j]][tour[(j+1)%N]]\
                            >dist[tour[i]][tour[j]]+dist[tour[(j+1)%N]][tour[i+1]]:
                    if j==N-1:
                        new_list = tour[i + 1:N]
                        tour[i + 1:N] = new_list[::-1]
                    else:
                        new_list = tour[i+1:j+1]
                        tour[i+1:j+1] = new_list[::-1]
                    count+=1
        if count==0: break


    # 二つの経路入れ替えた方が短ければ入れ替えるver2！
    while True:
        count=0
        for i in range(N-3):
            for j in range(i+3,N):
                if dist[tour[i]][tour[i+1]]+dist[tour[i+1]][tour[i+2]]+dist[tour[j]][tour[(j+1)%N]]\
                        >dist[tour[i]][tour[i+2]]+dist[tour[j]][tour[i+1]]+dist[tour[i+1]][tour[(j+1)%N]]:
                    if j==N-1:
                        new_list1 = tour[0:i+1]
                        new_list2 = tour[i+2:]
                        tour = new_list1+new_list2+[tour[i+1]]
                    else:
                        new_list1 = tour[0:i+1]
                        new_list2 = tour[i+2:j+1]
                        new_list3 = tour[j+1:]
                        tour= new_list1+new_list2+[tour[i+1]]+new_list3
                    count+=1
        if count==0: break
    return tour
    

'''
    # 二つの経路入れ替えた方が短ければ入れ替えるver3！
    
    while True:
        count=0
        for i in range(N-4):
            for j in range(i+4,N):
                if dist[tour[i]][tour[i+1]]+dist[tour[i+1]][tour[i+2]]+dist[tour[j]][tour[(j+1)%N]]+dist[tour[(j+1)%N]][tour[(j+2)%N]]\
                        >dist[tour[i]][tour[(j+1)%N]]+dist[tour[(j+1)%N]][tour[i+2]]+dist[tour[j]][tour[i+1]]+dist[tour[i+1]][tour[(j+2)%N]]:
                    if j==N-1:
                        new_list1 = tour[1:i + 1]
                        new_list2 = tour[i + 2:j+1]
                        tour = [tour[i + 1]]+new_list1 + [tour[(j+1)%N]]+ new_list2
                    elif j+1==N-1:
                        new_list1 = tour[0:i + 1]
                        new_list2 = tour[i + 2:j + 1]
                        tour = new_list1 + [tour[j + 1]] + new_list2 + [tour[i + 1]]
                    else:
                        new_list1 = tour[0:i+1]
                        new_list2 = tour[i+2:j+1]
                        new_list3 = tour[j+2:]
                        tour= new_list1+[tour[j+1]]+new_list2+[tour[i+1]]+new_list3
                    count+=1
        if count==0: break
    return tour
'''

if __name__ == '__main__':
    assert len(sys.argv) > 1
    tour = solve(read_input(sys.argv[1]))
    print_tour(tour)
