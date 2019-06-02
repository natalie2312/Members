
#include "Member.h"
#include <algorithm>
#include <iostream>
using namespace std;
namespace ariel{


int Member::counter = 0;

//Member Constructors//
Member::Member(){
	ID = ++counter;
}

//Member Distructor//
Member::~Member(){
    counter--;
	
    for_each(followers.begin(), followers.end(), [this](Member * other) { other->following.remove(this); });
    for_each(following.begin(), following.end(), [this](Member * other) { other->followers.remove(this); });
}

//return num of Followers//
int Member::numFollowers(){
return followers.size();
}

//return num of Following//
int Member::numFollowing(){
return following.size();
}

//return num of Members//
 int Member::count(){
return counter;
}

//folow Member//
void Member::follow(Member& name){
	 if(this == &name){
        printf("You cant follow yourself, please enter other name");
        return;
    }
	if (find(following.begin(), following.end(), &name) == following.end()) 
	{
		following.push_back(&name);
		name.followers.push_back(this);
	}
}
//unfollow Member//
void Member::unfollow(Member& name){
	 if(this == &name){
        printf("You cant unfollow yourself, please enter other name");
        return;
    }
	following.remove(&name);
	name.followers.remove(this);
}
}