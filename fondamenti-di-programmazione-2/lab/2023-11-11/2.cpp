#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Stats {
  unsigned frequenza = 0;
  set<string> tweets;
};

int main() {
  map<string, Stats> hashtags;

  unsigned n = 0;
  cout << "Numero di tweet: ";
  cin >> n;
  cin.ignore();

  for (int i = 0; i <= n; ++i) {
    string tweet = "";
    getline(cin, tweet);

    string::size_type start = tweet.find('#'), end = tweet.find(' ', start);

    while (start < tweet.size() && end < tweet.size()) {
      string ht = tweet.substr(start, end - start);

      if (hashtags.find(ht) != hashtags.end()) {
        ++hashtags[ht].frequenza;
        hashtags[ht].tweets.insert(tweet);
      } else {
        hashtags.insert({ht, {1, {tweet}}});
      }

      start = tweet.find('#', start + 1);
      end = tweet.find(' ', start);
    }
  }

  for (pair e : hashtags)
    cout << e.first << ": " << e.second.frequenza << endl;

  return 0;
}
