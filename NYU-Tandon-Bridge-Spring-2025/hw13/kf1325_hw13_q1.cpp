#include <iostream>
#include <vector>

using namespace std;

const int GRID_LIMIT = 20;
const int SPECIES_COUNT[] = { 100, 5 };
const int BREED_INTERVAL[] = { 3, 8 };
const int DDB_STARVE_INTERVAL = 3;

const char ANT_CHAR = 'o';
const char DDB_CHAR = 'X';
const char EMPTY_CELL = '-';

enum Direction { UP, DOWN, LEFT, RIGHT };
enum Species { ANT, DOODLEBUG };

class World;

class Organism
{
protected:
	int x, y, stepsSurvived;
	bool hasMoved = false;

public:
	Organism(int x = 0, int y = 0) : x(x), y(y), stepsSurvived(0) {}
	virtual ~Organism() {}

	virtual void move(World& world) = 0;
	virtual void breed(World& world) = 0;
	virtual Species getSpecies() const = 0;
	virtual Organism* createOffspring(int newXCell, int newYRow) const = 0;

	int getXCell() const { return x; }
	int getYRow() const { return y; }
	char displayChar();
	void setPosition(int newXCell, int newYRow) { x = newXCell; y = newYRow; }
	void setNewDirection(int& newXCell, int& newYRow, Direction direction) const;
	void incrementSurvival() { stepsSurvived++; }
	void resetSurvival() { stepsSurvived = 0; }
	void resetMoveFlag() { hasMoved = false; }
	bool getMoveFlag() const { return hasMoved; }
	void setMoveFlag() { hasMoved = true; }
};

class Ant : public Organism
{
public:
	Ant(int x, int y) : Organism(x, y) {}
	void move(World& world) override;
	void breed(World& world) override;
	Species getSpecies() const override { return ANT; };
	Organism* createOffspring(int newXCell, int newYRow) const override { return new Ant(newXCell, newYRow); }
};

class Doodlebug : public Organism
{
	int stepsStarved;
public:
	Doodlebug(int x, int y) : Organism(x, y), stepsStarved(0) {}
	void incrementStarvation() { stepsStarved++; }
	void resetStarvation() { stepsStarved = 0; }
	void move(World& world) override;
	void breed(World& world) override;
	void starve(World& world);
	Species getSpecies() const override { return DOODLEBUG; };
	Organism* createOffspring(int newXCell, int newYRow) const override { return new Doodlebug(newXCell, newYRow); }

};

class World
{
private:
	Organism* grid[GRID_LIMIT][GRID_LIMIT]{};

public:
	World();
	~World();
	void displayWorld();
	char displayCell(Organism* cell);
	void simulateWorld();
	bool isCellEmpty(int x, int y) const { return grid[y][x] == nullptr; }
	bool isInRange(int x, int y);
	Organism* getOrganism(int x, int y) const { return grid[y][x]; }
	void moveOrganism(int xCell, int yRow, int newXCell, int newYRow);
	void setOrganism(int xCell, int yRow, Organism* organism);
	void removeOrganism(Organism* organism);
};

int main()
{
	World world{};
	int time = 0;

	while (true)
	{
		cout
			<< "World at time "
			<< time
			<< ":"
			<< endl
			<< endl;

		world.displayWorld();
		world.simulateWorld();

		cout
			<< endl
			<< "Press ENTER to continue";
		cin.get();

		time++;
	}

	return 0;
}

World::World()
{
	srand(time(0));

	for (auto& row : grid)
		for (auto& cell : row)
			cell = nullptr;

	int antCount = 0, ddbCount = 0;

	while (antCount < SPECIES_COUNT[ANT] || ddbCount < SPECIES_COUNT[DOODLEBUG])
	{
		int yRow = rand() % GRID_LIMIT;
		int xCell = rand() % GRID_LIMIT;
		Species organism = (Species)(rand() % 2);

		if (!grid[yRow][xCell])
			switch (organism)
			{
			case ANT:
				if (antCount < SPECIES_COUNT[ANT])
				{
					grid[yRow][xCell] = new Ant(xCell, yRow);
					antCount++;
				}
				break;
			case DOODLEBUG:
				if (ddbCount < SPECIES_COUNT[DOODLEBUG])
				{
					grid[yRow][xCell] = new Doodlebug(xCell, yRow);
					ddbCount++;
				}
				break;
			}
	}

}

World::~World()
{
	for (auto& row : grid)
		for (auto& cell : row)
			delete cell;
}

void World::displayWorld()
{
	for (auto& row : grid)
	{
		for (auto& cell : row)
			cout
			<< displayCell(cell)
			<< ' ';
		cout
			<< endl;
	}
}

char World::displayCell(Organism* cell)
{
	if (cell)
		return cell->displayChar();
	return EMPTY_CELL;

}

void World::simulateWorld()
{
	for (auto& row : grid)
		for (auto& cell : row)
			if (cell)
				cell->resetMoveFlag();

	vector<Organism*> organisms, doodlebugs, ants;

	for (auto& row : grid)
		for (auto& cell : row)
			if (cell)
				if (cell->getSpecies() == DOODLEBUG)
					doodlebugs.push_back(cell);

	for (auto ddb : doodlebugs)
		ddb->move(*this);

	for (auto& row : grid)
		for (auto& cell : row)
			if (cell)
				if (cell->getSpecies() == ANT)
					ants.push_back(cell);

	for (auto ant : ants)
		ant->move(*this);


	for (auto& row : grid)
		for (auto& cell : row)
			if (cell)
				organisms.push_back(cell);

	for (auto organism : organisms) {
		organism->breed(*this);
	}

	for (auto organism : organisms) {
		if (organism->getSpecies() == DOODLEBUG) {
			static_cast<Doodlebug*>(organism)->starve(*this);
		}
	}
}

bool World::isInRange(int x, int y)
{
	return x >= 0 && x < GRID_LIMIT && y >= 0 && y < GRID_LIMIT;
}

void World::moveOrganism(int xCell, int yRow, int newXCell, int newYRow)
{
	grid[newYRow][newXCell] = grid[yRow][xCell];
	grid[yRow][xCell] = nullptr;
	grid[newYRow][newXCell]->setPosition(newXCell, newYRow);
}

void World::setOrganism(int xCell, int yRow, Organism* organism)
{
	if (grid[yRow][xCell] && grid[yRow][xCell] != organism)
		delete grid[yRow][xCell];
	grid[yRow][xCell] = organism;
	if (organism)
		organism->setPosition(xCell, yRow);
}

void World::removeOrganism(Organism* organism)
{
	grid[organism->getYRow()][organism->getXCell()] = nullptr;
	delete organism;
}

void Organism::move(World& world)
{
	if (getMoveFlag()) return;
	setMoveFlag();
	Direction direction = (Direction)(rand() % 4);
	int newXCell, newYRow;
	setNewDirection(newXCell, newYRow, direction);
	if (world.isInRange(newXCell, newYRow) && world.isCellEmpty(newXCell, newYRow))
		world.moveOrganism(x, y, newXCell, newYRow);
}

void Organism::breed(World& world)
{
	if (this->stepsSurvived >= BREED_INTERVAL[(int)this->getSpecies()])
	{
		vector<vector<int>> adjacentEmptyCell;
		for (Direction direction : { UP, DOWN, LEFT, RIGHT })
		{
			int newXCell, newYRow;
			setNewDirection(newXCell, newYRow, direction);
			if (world.isInRange(newXCell, newYRow) && world.isCellEmpty(newXCell, newYRow))
			{
				adjacentEmptyCell.push_back({ newXCell, newYRow });
			}
		}
		if (!adjacentEmptyCell.empty())
		{
			int randomIndex = rand() % adjacentEmptyCell.size();
			int newXCell = adjacentEmptyCell[randomIndex][0];
			int newYRow = adjacentEmptyCell[randomIndex][1];
			world.setOrganism(newXCell, newYRow, createOffspring(newXCell, newYRow));
			resetSurvival();
		}
	}
}

char Organism::displayChar()
{
	switch (getSpecies())
	{
	case ANT: return ANT_CHAR;
	case DOODLEBUG: return DDB_CHAR;
	default: return EMPTY_CELL;
	}
}

void Organism::setNewDirection(int& newXCell, int& newYRow, Direction direction) const
{
	newXCell = x;
	newYRow = y;

	switch (direction)
	{
	case UP:
		newYRow++;
		break;
	case DOWN:
		newYRow--;
		break;
	case LEFT:
		newXCell--;
		break;
	case RIGHT:
		newXCell++;
		break;
	}
}

void Ant::move(World& world)
{
	if (getMoveFlag()) return;
	setMoveFlag();
	Organism::move(world);
	incrementSurvival();
}

void Ant::breed(World& world)
{
	Organism::breed(world);
}

void Doodlebug::move(World& world)
{
	if (getMoveFlag()) return;
	setMoveFlag();
	vector<vector<int>> adjacentAnts;
	for (Direction direction : {UP, DOWN, LEFT, RIGHT}) {

		int newXCell, newYRow;
		setNewDirection(newXCell, newYRow, direction);
		if (world.isInRange(newXCell, newYRow) && world.getOrganism(newXCell, newYRow) && world.getOrganism(newXCell, newYRow)->getSpecies() == ANT) {
			adjacentAnts.push_back({ newXCell, newYRow });
		}
	}
	if (!adjacentAnts.empty()) {
		int randomIndex = rand() % adjacentAnts.size();
		int newXCell = adjacentAnts[randomIndex][0];
		int newYRow = adjacentAnts[randomIndex][1];
		world.removeOrganism(world.getOrganism(newXCell, newYRow));
		world.moveOrganism(x, y, newXCell, newYRow);
		resetStarvation();
	}
	else
	{
		Organism::move(world);
		incrementStarvation();
	}
	incrementSurvival();
}

void Doodlebug::breed(World& world)
{
	Organism::breed(world);
}

void Doodlebug::starve(World& world)
{
	if (stepsStarved >= DDB_STARVE_INTERVAL) {
		world.removeOrganism(this);
	}
}
