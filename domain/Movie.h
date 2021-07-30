#ifndef INC_2021_SUMMER_CSCI2421_MOVIE_H
#define INC_2021_SUMMER_CSCI2421_MOVIE_H

#include "string"
#include "memory"
#include "Actor.h"
#include "list"
#include "vector" // added this, can remove if run into errors

/**TODO 0: Clean up includes.  */

using namespace std;

class Movie {
private:
    string title;
    int releaseYear;
    list<shared_ptr<Actor>> actors; /**TODO 14: Make it a list.  */

public:
    explicit Movie();

    explicit Movie(const string &aTitle, int year);

    ~Movie();

    string getTitle() const;

    void setTitle(const string &aTitle);

    int getReleaseYear() const;

    void setReleaseYear(int year);

    friend ostream &operator<<(ostream &out, const Movie &aMovie);

    bool addActor(const shared_ptr<Actor> &anActor);

    bool removeActor(const shared_ptr<Actor> &anActor);

    vector<shared_ptr<Actor>> getActors() const;

    /**TODO 15: Add operator< for shared_ptr (see StreamingService::sortMovies()).  */

    friend bool operator < (const shared_ptr<Movie> &lhs, const shared_ptr<Movie> &rhs);
};

#include "Movie.cpp"


#endif //INC_2021_SUMMER_CSCI2421_MOVIE_H
