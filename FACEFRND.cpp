#include <iostream>
#include <set>
using namespace std;

int main() {

	set<int> friendsOfFriends;
	set<int> friends;
	
	int nTestCases;
	int currentFriend, nCurrentFriendOfFriend, currentFriendOfFriend;
	scanf("%d", &nTestCases);
	
	while(nTestCases--){
		scanf("%d", &currentFriend);
		friends.insert(currentFriend);
		if(friendsOfFriends.find(currentFriend)!= friendsOfFriends.end()){
			//This friend is present in friend of friend list
			//Delete it
			
			friendsOfFriends.erase(currentFriend);
		}
		scanf("%d", &nCurrentFriendOfFriend);
		while(nCurrentFriendOfFriend--){
			scanf("%d", &currentFriendOfFriend);
			if(friendsOfFriends.find(currentFriendOfFriend) == friendsOfFriends.end()){
				//This Friend of Friend not in the list
				//Insert it
				if(friends.find(currentFriendOfFriend) == friends.end()) {
					friendsOfFriends.insert(currentFriendOfFriend);
				}
				
			}
		}
	}
	
	
	cout<<friendsOfFriends.size();

	return 0;
}