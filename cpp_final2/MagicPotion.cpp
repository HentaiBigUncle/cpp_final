#include "MagicPotion.h"

MagicPotion::MagicPotion(int mHp, int mMp, int atk, int mAtk, int mDfs, int r, int dfs, int _heal, int _mp, int _damage, int _gold, string n) :
	Item(mHp, mMp, atk, mAtk, mDfs, r, dfs, _heal, _mp, _damage, _gold, n)
{

}
void MagicPotion::useItem(Player& p, enemy& e) const
{
	p.getCharacter()->changeMp(mp);
	cout << "You restore " <<mp<<" mp" << endl;
}