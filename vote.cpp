#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
	const string testFilename = "test1.txt";

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

	int v;
	vector<int> votes = {};

	while (cin >> v)
	{
		cout << v;
		votes.push_back(v);
	}


	
	

	//char c = ifs.get();
	//cout << getNumberOfCandidates(ifs);
	//cout << c;

	ifs.close();
	

	return 0;
}