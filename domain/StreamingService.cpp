
#include "iostream"
#include "string"
#include "regex"

/**TODO 3: Fix Constructor*/
/**********************************************************************************************************************/
StreamingService::StreamingService(): movies(make_unique<list<shared_ptr<Movie>>>()),
                                      actors(make_unique<list<shared_ptr<Actor>>>()){}

/**TODO 4: Fix Destructor.
 * Hint: need to remove all the elements of both list.
 * Check List methods
 */
/**********************************************************************************************************************/
StreamingService::~StreamingService() {
    movies->clear();
    actors->clear();
}

/**TODO 5: Fix Add Movie
 * Hint: STL always adds. so will return true always
 */
/**********************************************************************************************************************/
bool StreamingService::addMovie(const string& title, int year){
    bool added;
    shared_ptr<Movie> aMovie = make_shared<Movie>(title, year);
    this->movies->push_back(aMovie);
    added = true;
    return added;

}

/**TODO 5: Fix Add Actor
 * Hint: STL always adds. so will return true always
 */
/**********************************************************************************************************************/
bool StreamingService::addActor(const string& name){
    bool added;
    shared_ptr<Actor> anActor = make_shared<Actor>(name);
    this->actors->push_back(anActor);
    added = true;
    return added;
}

/**TODO 6: Fix Add Actor to Movie
 * Hint: is there anything to do?
 */
/**********************************************************************************************************************/
bool StreamingService::addActorToMovie(const string& title, const string& actorName){
    shared_ptr<Movie> aMovie;
    shared_ptr<Actor> anActor;
    aMovie = searchMovieExact(title);
    anActor = searchActor(actorName);
    if (aMovie != nullptr && anActor != nullptr)
        return aMovie->addActor(anActor);
    else
        return false;
}


/**TODO 7: Fix isMovieAvailable
 * Hint: is there anything to do?
 */
/**********************************************************************************************************************/
bool StreamingService::isMovieAvailable(const string& title){
    return (searchMovieExact(title) != nullptr);
}


/**TODO 8: Fix search movie exact
 * Hint: remember that the "for each" receives an object. when using pointers you need to de-reference the pointer
 * to retrieve the object. Check interlude 4.
 */
/**********************************************************************************************************************/
shared_ptr<Movie> StreamingService::searchMovieExact(const string& title){
    for (const shared_ptr<Movie>& aMovie: *this->movies)
        if (aMovie->getTitle() == title)
            return aMovie;
    return nullptr;
}

/**TODO 10: Fix search movie Pattern
 * Hint: similar comments as search movie exact.
 */
/**********************************************************************************************************************/
vector<shared_ptr<Movie>> StreamingService::searchMoviePattern(const string& titlePattern){

    vector<shared_ptr<Movie>> foundMovies;

    string expression (".*"+ titlePattern+".*");
    transform(expression.begin(), expression.end(), expression.begin(), ::tolower);
    const regex regExpression(expression);

    for (const shared_ptr<Movie>& aMovie: *this->movies) {
        string title = aMovie->getTitle();
        transform(title.begin(), title.end(), title.begin(), ::tolower);
        if (regex_match(title, regExpression))
            foundMovies.push_back(aMovie);
    }

    return foundMovies;
}

/**TODO 11: Fix search actor
 * Hint: same comment as before re: pointers.
 */
/**********************************************************************************************************************/
shared_ptr<Actor> StreamingService::searchActor(const string& actorName){
   // make_unique<list<shared_ptr<Actor>>>
    //
    for (const  shared_ptr<Actor>& anActor: *this->actors)
        if (anActor->getName() == actorName)
            return anActor;
    return nullptr;
}

/**TODO 12: Fix operator<<
 * Hint: same comment as before re: pointers.
 */
/**********************************************************************************************************************/
std::ostream& operator<<(std::ostream& out, const StreamingService& service) {
    out << std::endl;
    out << "Movies in the Streaming Service: " << std::endl;
    for(const shared_ptr<Movie>& aMovie : *service.movies)
        out<< *aMovie << std::endl;
    out<< "--------------------------------------------"<<std::endl;

    return out;
}




/**********************************************************************************************************************/
void StreamingService::sortMovies() const {
    /**TODO 13: Implement sortMovies
     * Hint: sorts the movies list. check the interface
     *
     * Caveats: the list contains pointers, so, sorting by default will compare two movie pointers by using the operator<
     * You need to have a friend redefinition of movie operator < that compares two shared pointers to movies.
     * The best place to add that method is in Movie.h
     * After implementing, CHECK the movie order when displaying the streaming service, after sorting, is correct.
     */
     movies->sort();

}

