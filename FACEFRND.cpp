#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

int main() {
    short nTestCases, nFriends;
    scanf("%hd", &nTestCases);
    set<short> friendsAndFriendsofFriend;

    short bobFriend, temp;

    for (int i = 0; i < nTestCases ; i++) {
        scanf("%hd", &bobFriend);
        friendsAndFriendsofFriend.insert(bobFriend);
        scanf("%hd", &nFriends);
        while(nFriends--) {
            scanf("%hd", &temp);
            friendsAndFriendsofFriend.insert(temp);
        }
    }

    printf("%d", friendsAndFriendsofFriend.size() - nTestCases);

    return 0;
}