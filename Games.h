#include <iostream>
#include <string>
using namespace std;
#pragma once

class Games {
    private:
        string title;
        string platform_type;
        string genre;
        float rating;
    public:
        Games(string t, string p, string g, float r) : title(t), platform_type(p), genre(g), rating(r) {}
        //getters
        string get_title() const { return title; }
        string get_platform_type() const { return platform_type; }
        string get_genre() const { return genre; }
        float get_rating() const { return rating; }
        //setters
        void set_title(const string& t) { title = t; }
        void set_platform_type(const string& p) { platform_type = p; }
        void set_genre(const string& g) { genre = g; }
        void set_rating(float r) { rating = r; };
};