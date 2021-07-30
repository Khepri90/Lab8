
#include "iostream"


/**********************************************************************************************************************/
Movie::Movie() : Movie("", 0) {}


/**TODO 16: Fix Constructor*/
/**********************************************************************************************************************/
Movie::Movie(const string &aTitle, int year): title(aTitle), releaseYear(year), actors(list<shared_ptr<Actor>>()) {}

/**TODO 17: Fix Destructor
 * Hint: Using pointers, is just remove all the pointers from the list.
 * Check list interface
 */
/**********************************************************************************************************************/
Movie::~Movie() {
    actors.clear();
}

/**********************************************************************************************************************/
string Movie::getTitle() const {
    return this->title;
}

/**********************************************************************************************************************/
void Movie::setTitle(const string &aTitle) {
    this->title = aTitle;
}

/**********************************************************************************************************************/
int Movie::getReleaseYear() const {
    return releaseYear;
}

/**********************************************************************************************************************/
void Movie::setReleaseYear(int year) {
    this->releaseYear = year;
}

/**TODO 18: Fix Operator << */
/**********************************************************************************************************************/
ostream& operator<<(ostream& out, const Movie& aMovie) {
    out << ">>"
        << aMovie.getTitle() << "--"
        << aMovie.getReleaseYear() << "<<" <<endl;

    for (const shared_ptr<Actor>& anActor: aMovie.getActors())
        out << *anActor <<endl;

    return out;
}

/**TODO 19: Fix addActor*/
/**********************************************************************************************************************/
bool Movie::addActor(const shared_ptr<Actor>& anActor) {
    for(const shared_ptr<Actor>& theActor: this->actors){
        if(theActor == anActor)
            return false;
    }
    this->actors.push_back(anActor);
    return true;
}

/**TODO 20: Fix removeActor*/
/**********************************************************************************************************************/
bool Movie::removeActor(const shared_ptr<Actor> &anActor) {
    actors.pop_back();
    return true;
}


/**TODO 21: Fix getActors
 * HINT: you need to create the vector by yourself.
 * Here some useful links: https://www.techiedelight.com/convert-list-to-vector-cpp/
 */
/**********************************************************************************************************************/
vector<shared_ptr<Actor>> Movie::getActors() const {
    vector<shared_ptr<Actor>> result;

    for(const shared_ptr<Actor>& Actors: this->actors){
        result.push_back(Actors);
    }
    return result;
}

bool operator < (const shared_ptr<Movie> &lhs, const shared_ptr<Movie> &rhs){
    return lhs->getTitle() < rhs->getTitle();
}
