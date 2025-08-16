#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#ifdef _DEBUG
#include <windows.h>
#endif

using namespace std;

class PersonNode
{
public:
	string name;
	double amountPaid;
	double amountOwed;
	PersonNode* nextPersonNode;
	PersonNode(string n, double p) : name(n), amountPaid(p), amountOwed(0), nextPersonNode(nullptr) {}
};
typedef PersonNode* PersonNodePtr;

class PersonList
{
public:
	double total;
	int count;
	PersonNodePtr head;
	PersonList() : total(0), count(0), head(nullptr) {}
	~PersonList();
	PersonList(const PersonList&) = delete;
	PersonList& operator=(const PersonList&) = delete;
	void processBill();
private:
	ifstream infile;
	PersonList& open_input_file();
	PersonList& read_input_file();
	PersonList& updateAmountsOwed();
	PersonList& reimburse();
	void append(const string& name, double amountPaid);
	vector<PersonNodePtr> toVector() const;
};

PersonList& PersonList::open_input_file()
{
constexpr auto RESET = "\033[0m";
constexpr auto GREEN = "\033[32m";
	string filename;
#ifdef _DEBUG
	char buffer[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, buffer);
	cout 
		<< "Working directory: " 
		<< GREEN
		<< buffer 
		<< RESET
		<< endl;
	filename = "hw15\\testInput1.txt";
#else
	cout
		<< "Enter the filename: "
		<< GREEN;
	cin >> filename;
	cout
		<< RESET;
#endif
	infile.open(filename);

	while (!infile)
	{
		cout
			<< "Bad filename."
			<< endl;
		cout
			<< "Enter the filename: "
			<< GREEN;
		cin >> filename;
		cout
			<< RESET;
		infile.clear();
		infile.open(filename);
	}

	return *this;
}

PersonList& PersonList::read_input_file()
{
	double amountPaid;
	string name;
	while (infile >> amountPaid)
	{
		infile.get();
		getline(infile, name);
		append(name, amountPaid);
	}

	infile.close();

	return *this;
}

int main()
{
	PersonList pList;
	pList.processBill();
	return 0;
}

PersonList::~PersonList()
{
	PersonNodePtr curr = head;
	while (curr)
	{
		PersonNodePtr next = curr->nextPersonNode;
		delete curr;
		curr = next;
	}
}

void PersonList::append(const string& name, double amountPaid)
{
	PersonNodePtr newNode = new PersonNode(name, amountPaid);
	total += amountPaid;
	count++;
	if (!head)
		head = newNode;
	else
	{
		PersonNodePtr curr = head;
		while (curr->nextPersonNode)
			curr = curr->nextPersonNode;
		curr->nextPersonNode = newNode;
	}
}

void PersonList::processBill()
{
	(*this)
		.open_input_file()
		.read_input_file()
		.updateAmountsOwed()
		.reimburse();
}

PersonList& PersonList::updateAmountsOwed()
{
	if (count == 0) return *this;
	double target = total / count;
	PersonNodePtr curr = head;
	while (curr)
	{
		curr->amountOwed = curr->amountPaid - target;
		curr = curr->nextPersonNode;
	}

	return *this;
}

PersonList& PersonList::reimburse()
{
	vector<PersonNodePtr> people = toVector();
	vector<PersonNodePtr> creditors, debtors;

	for (auto p : people)
		if (p->amountOwed > 0)
			creditors.push_back(p);
		else if (p->amountOwed < 0)
			debtors.push_back(p);
		else
			cout
			<< p->name
			<< ", you don't need to do anything"
			<< endl;

	int i = 0, j = 0;
	while (i < debtors.size() && j < creditors.size())
	{
		PersonNodePtr debtor = debtors[i];
		PersonNodePtr creditor = creditors[j];
		double owe = -debtor->amountOwed;
		double toReceive = creditor->amountOwed;
		double payment = min(owe, toReceive);

		cout
			<< debtor->name
			<< ", you give "
			<< creditor->name
			<< " $"
			<< fixed 
			<< setprecision(6)
			<< payment
			<< endl;

		debtor->amountOwed += payment;
		creditor->amountOwed -= payment;

		if (abs(debtor->amountOwed) < 1e-6) i++;
		if (abs(creditor->amountOwed) < 1e-6) j++;
	}

	cout
		<< "In the end, you should all have spent around $"
		<< fixed
		<< setprecision(2)
		<< total / count;

	return *this;
}

vector<PersonNodePtr> PersonList::toVector() const
{
	vector<PersonNodePtr> v;
	PersonNodePtr curr = head;
	while (curr)
	{
		v.push_back(curr);
		curr = curr->nextPersonNode;
	}
	return v;
}
