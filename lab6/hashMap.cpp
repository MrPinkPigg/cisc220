/*
 * hashMap.cpp
 *
 * Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "hashNode.hpp"
#include "hashMap.hpp"

using namespace std;


hashMap::hashMap(bool hash, bool coll){
	first = "";
	numKeys = 0;
	mapSize = 100;
	map = new hashNode* [mapSize];
	for(int i = 0; i < mapSize; i++){
		map[i] = NULL;
	}
	h1 = hash;
	c1 = coll;
	collisionct1 = 0;
	collisionct2 = 0;
}

// adds a node to the map at the correct index based on the key string, and then inserts the value into the
// value field of the hashNode
// Must check to see whether there's a node at that location. If there's nothing there (it's NULL), add the
// hashNode with the keyword and value.
// If the node has the same keyword, just add the value to the list of values.
//If the node has a different keyword, keep calculating a new hash index until either the keyword matches
// the node at that index's keyword, or until the
// map at that index is NULL, in which case you'll add the node there.
//This method also checks for load, and if the load is over 70%, it calls the reHash method to create a new
// longer map array and rehash the values
//if h1 is true, the first hash function is used, and if itís false, the second is used.
//if c1 is true, the first collision method is used, and if itís false, the second is used
void hashMap::addKeyValue(string k, string v){
    int index = getIndex(k);

    if(map[index] == NULL){
    	map[index] = new hashNode(k, v);
    	numKeys++;
    } else {
    	map[index]->addValue(v);
    }
    
    //Rehash the map when at 70% capacity
    if(numKeys >= this->mapSize * .7){
        reHash();
    }
}

/*
 * Determine the index at which to insert a specified key.
 * Uses specified hashing algorithm and collision algorithms until
 * the index is null or matching the supplied key
 */
int hashMap::getIndex(string k){
    int index;
    
    if(h1){
        index = calcHash(k);
    } else {
        index = calcHash2(k);
    }
    
    if(map[index] == NULL || map[index]->keyword == k){
        return index;
    } else {
		collisionct1++;
		if(c1){
			index = collHash1(k, index);
		} else {
			index = collHash2(k, index);
		}
		return index;
    }
}

/*
 * Sums the ascii values of each character in the provided string,
 * takes the sum % mapSize to determine the position to place the key in the map
 * @return output % mapSize - the index at which to place the key in the map
 */
int hashMap::calcHash(string k){
	int output = 0;
	int length = k.length();

	for(int i = 0; i < length; i++){
		output += int(k.at(i));
	}

	return output % this->mapSize;
}

/*
* Iterates through the provided string and mutiplies the ascii value of each character
* times 21^i, where i is the position of the character in the string.
* Takes the calculated value % mapSize to determine the position to place the key in the map
* @return output % mapSize - the index at which to place the key in the map
*/
int hashMap::calcHash2(string k){
	int output = 0;
	int length = k.length();

	for(int i = 0; i < length; i++){
        output += int(k.at(i)) * 21^i;
    }

	return output % this->mapSize;
}

// I used a binary search on an array of prime numbers to find the closest prime
// to double the map Size, and then set mapSize to that new prime. You can include as one of the fields an array of
// prime numbers, or you can write a function that calculates the next prime number. Whichever you prefer.
void hashMap::getClosestPrime(){
    int curr = this->mapSize * 2;
    bool primeFound = false;
    
    //Find the next prime number
    while(!primeFound){
        curr++;
        for(int i = 2; i < curr/2; i++){
            if(curr % i == 0){
                primeFound = false;
                break;
            } else {
                primeFound = true;
            }
        }
    }
    
    this->mapSize = curr;
}

/*
 * doubles size of array, and rehashes the keys in the map
 */
void hashMap::reHash(){
    int oldSize = this->mapSize;
    getClosestPrime();
    int newSize = this->mapSize;

    //Create a new array to hold rehashed nodes in the updated size
    hashNode **n = map;
    map = new hashNode *[newSize];
    for(int i = 0; i < newSize; i++){
    	map[i] = NULL;
    }

    for(int i = 0; i < oldSize; i++){
    	if(n[i] != NULL){
    		int index = getIndex(n[i]->keyword);
    		map[index] = n[i];
    	}
    }
}

/*
 * Method for dealing with collisions during hashing - increments
 * the hash Index of the key and returns it. Returns 0 if incrementing
 * the index results in a value larger than the size of the hashMap.
 */
int hashMap::collHash1(string k, int i){

	while(map[i] != NULL){
		if(map[i]->keyword == k){
			return i;
		} else {
			collisionct2++;
			if(i == mapSize - 1){
				i = 0;
			} else {
				i++;
			}
		}
	}

	return i;
}

/*
 * Method for dealing with collisions during hashing - increments
 * the hash Index of the key by i^2, where i increments each time
 * another collision occurs, and returns it.
 */
int hashMap::collHash2(string k, int i){
	int count = 1;
	while(map[i] != NULL){
		 if(map[i]->keyword == k){
			 return i;
		 } else {
			 collisionct2++;
			 i += count^2;
			 i = i % mapSize;
			 count++;
		 }
	}

	return i;
}

int hashMap::findKey(string k){
    int index = getIndex(k);
    if(map[index] == NULL){
    	return -1;
    } else {
    	return index;
    }
}

void hashMap::printMap(){
	int size = this->mapSize;
    for(int i = 0; i < size; i++){
    	if(map[i] == NULL){
    		cout <<  i  << ": "   << endl;
    	} else {
			cout << i << ": " << map[i]->keyword << ": ";
			for(int x = 0; x < map[i]->valuesSize; x++){
				if(map[i]->values[x] == ""){
					break;
				} else {
					cout << map[i]->values[x] << ", ";
				}
			}
			cout << endl;
    	}
    }
}
