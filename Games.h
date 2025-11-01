#include <iostream>
#include <string>
#include "data_src/Game.h"
using namespace std;
#pragma once

class Games {
    private:
        string title;
        string platform_type;
        vector<string> genre;
        float rating;
    public:
        Games(string t, string p, vector<string> g, float r) : title(t), platform_type(p), genre(g), rating(r) {}
        
        //getters (not sure if needed because data already has the gettitle, etc functions)
        string get_title() const { return title; }
        string get_platform_type() const { return platform_type; }
        vector<string> get_genre() const { return genre; }
        float get_rating() const { return rating; }

        //setters
        void set_title(const string& t) { title = t; }
        void set_platform_type(const string& p) { platform_type = p; }
        void set_genres(const vector<string>& g) { genre = g; }
        void set_rating(float r) { rating = r; };
};

std::vector<Games> convertBridgesToLocal(const std::vector<Game>& bridgeList);

void runHeapTopNOnDataset(const std::vector<Game>& bridgeList, int N);

std::vector<Games> getTopN_Heap(const std::vector<Games>& allGames, int N);

void printGame(const Games& g);
