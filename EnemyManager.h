#pragma once
#include "Enemy.h"
#include "Player.h"

class EnemyManager :public Singleton<EnemyManager>
{
private:
	//メンバ定数
	int MAX_VALUE = 1;
	Vec3 attackVec = Vec3();
	//メンバ変数
	vector<Enemy> enemy;
public:
	//メンバ関数
	EnemyManager();
	friend Singleton<EnemyManager>;

	void Generate(Player& player);

	void Update(Player& player);

	void CD_PushBackPlayer(Player& player);

	void Draw();

	Enemy GetEnemy(int i) { return enemy[i]; }
	Vec3 GetAttackVec() { return attackVec; }
};