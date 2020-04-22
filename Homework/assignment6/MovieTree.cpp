#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
  root = NULL;
}

void destroyAllTheThings(MovieNode * current) {
  if (current != NULL) {
    destroyAllTheThings(current -> left);
    destroyAllTheThings(current -> right);
    delete current;
  }
}
MovieTree::~MovieTree() {
  destroyAllTheThings(root);
  root = NULL;
}


void printMovies(MovieNode * current) {
    if (current == NULL) 
        return; 
    printMovies(current->left); 
      cout << "Movie: " << current -> title << " " << current -> rating << endl;
    printMovies(current->right); 
}

void MovieTree::printMovieInventory() {
  if (root == NULL) {
    cout << "Tree is Empty. Cannot print" << endl;
  } else {
     printMovies(root);
  }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //Save data to temp member
  MovieNode * newMovie = new MovieNode(ranking, title, year, rating);

  if (root == NULL) {
    root = newMovie;
    return;
  } else {
    MovieNode * current = root;
    bool added = false;
    while (added == false) {
      if (newMovie ->title < current -> title) {
        if (current -> left == NULL) {
          current -> left = newMovie;
          added = true;
          break;
        } else {
          //move left
          current = current -> left;
        }
      } else if (newMovie -> title > current -> title) {
        if (current -> right == NULL) {
          current -> right = newMovie;
          added = true;
          break;
        } else {
          //move left
          current = current -> right;
        }
      } else {
        cout << "ERROR" << endl;
        break;
      }
    }
  }
}

void MovieTree::findMovie(string title) {
  bool repeat = true;
  bool found = false;
  MovieNode * current = root;
  while (repeat){
    if (current == NULL) {
      repeat = false;
    } else if (current -> title == title) {
        found = true;
        repeat = false;
    } else if (title < current -> title) {
        //move left
        current = current -> left;
    } else if (title > current -> title) {
        //move right
        current = current -> right;
    } else {
      repeat = false;
    }
  }
  if (found) {
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << current -> ranking << endl;
    cout << "Title  :" << current -> title << endl;
    cout << "Year   :" << current -> year << endl;
    cout << "rating :" << current -> rating << endl;
    repeat = false;
  } else {
    cout << "Movie not found." << endl;
    repeat = false;
  }

}

void printQuery(MovieNode * current, float minRating, int minYear) {
    if (current == NULL) 
        return; 
    if (current -> rating >= minRating && current ->year >= minYear) {
      cout << current -> title << "(" << current -> year << ") " << current -> rating << endl;
    }
    printQuery(current->left, minRating, minYear); 

    printQuery(current->right, minRating, minYear); 
}

void MovieTree::queryMovies(float rating, int year) {
  if (root == NULL) {
    cout << "Tree is Empty. Cannot print" << endl;
  } else {
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    printQuery(root, rating, year);
  }
}

void calcTotal(MovieNode * current, float &total, int &count) {
    if (current == NULL) 
        return; 
    calcTotal(current->left, total, count); 
      total = total + current -> rating;
      count++;
    calcTotal(current->right, total, count); 
}

void MovieTree::averageRating() {
  float total = 0;
  int count = 0;
  calcTotal(root, total, count);
  if (count == 0) {
    cout << "Average Rating:0.0" << endl;
  } else {
    cout << "Average Rating:" << total/count << endl;
  }
}

void printLevel(MovieNode * current, int level) {
  if (current == NULL) 
      return; 
  if (level == 0) {
      cout << "Movie: " << current -> title << " " << current -> rating << endl;
      return;
  } else {
      printLevel(current->left, level-1); 
      printLevel(current->right, level-1); 
  } 
}

void MovieTree::printLevelNodes(int level) {
  printLevel(root, level); 
}