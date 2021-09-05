#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}

void print(pair<int, int> p)
{
	cout << "Number of candidate: " << p.first << "\t" << "Votes: " << p.second << endl;
}


int main()
{
	// *** Get Votes From File ***
	const string testFilename = "test3.txt";

	ifstream ifs(testFilename, ifstream::in);
	if (!ifs.good())  // checks if filename is correct
	{
		cout << "Cannot find input file.\n";
		return 1;
	}

	streambuf* sb = ifs.rdbuf();  // gets pointer to the stream buffer
	cin.rdbuf(sb);  // assing streambuf to cin

	int N = 0;  // number of candidates
	int M = 0;  // number of votes
	cin >> N >> M;  // gets N and M from streambuf

	// Get votes:
	int v;
	vector<int> votes = {};
	while (cin >> v)
		votes.push_back(v);

	ifs.close();


	// *** Find The Winner ***
	map<int, int> candidates_votes;

	for (int i = 1; i <= N; ++i)
		candidates_votes[i] = 0;  // at beginning every candidate has 0 votes

	for (auto vote: votes)
	{
		if (vote == 0)  // checks if vote is valid
			continue;
		else
			++candidates_votes[vote];  // increment number of votes
	}

	pair<int, int> winner;  // first winner (there might be more winners)
	winner = *max_element(candidates_votes.begin(), candidates_votes.end(), compare);  // finds first candidate with maximum number of votes
	
	int max_votes = winner.second;  // maximum value of votes

	// Checks if someone else (other candidate) has max_vote
	vector<pair<int, int>> winners = {};  // all winners
	for (auto cv : candidates_votes)
	{
		if (cv.second == max_votes)
			winners.push_back(cv);
	}

	// Prints all winners
	for (auto w : winners)
		print(w);

	return 0;
}