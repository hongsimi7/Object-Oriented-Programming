#include <iostream>
#include "map.h"
#include "character.h"
#include "monster.h"
#include "shop.h"
#include <cstdlib>

int main()
{
	int user;				//���� �Է�
	int exit = 0;			//������ ��ȣ
	char direction;			//���� ���� �Է�
	int game_over = 0;		//���� ��� ��ȣ
	int monster_out = 0;	//���� ��� ��ȣ
	int shop_out = 0;		//���� ������ ��ȣ

	std::cout << "========================================================" << std::endl;				//�ʱ� ȭ��
	std::cout << "========================================================" << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << " #######                        ######  ######   #####  " << std::endl;
	std::cout << "    #    ###### #    # #####    #     # #     # #     # " << std::endl;
	std::cout << "    #    #       #  #    #      #     # #     # #       " << std::endl;
	std::cout << "    #    #####    ##     #      ######  ######  #  #### " << std::endl;
	std::cout << "    #    #        ##     #      #   #   #       #     # " << std::endl;
	std::cout << "    #    #       #  #    #      #    #  #       #     # " << std::endl;
	std::cout << "    #    ###### #    #   #      #     # #        #####  " << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << "========================================================" << std::endl << std::endl;
	std::cout << "----- Menu -----" << std::endl;
	std::cout << "1. Start game" << std::endl;
	std::cout << "2. Exit" << std::endl;

	while (true)
	{
		if (exit == 1)				//���� ������
		{
			std::cout << "Exit...";
			break;
		}
		if (game_over == 1)  break;	//���ӿ���

		std::cout << "> ";
		std::cin >> user;

		if (user == 1)			//���� ����
		{
			std::cout << "Game start!" << std::endl << std::endl;
			Map gamemap;					//�ʻ���
			Character game_char;			//ĳ���� ����
			Shop game_shop;					//���� ����

			while (true)
			{
				if (game_over == 1) break; //���� ������
				monster_out = 0;
				shop_out = 0;

				gamemap.show();
				std::cout << "1. Choose direction\n";
				std::cout << "2. Show character status\n";
				std::cout << "3. Exit game\n";
				std::cout << "> ";
				std::cin >> user;

				if (user == 1)				//���� ����
				{
					std::cout << "Where do you want to go?\n";

					while (true)
					{
						if (game_over == 1 || monster_out == 1 || shop_out == 1) break;		//���� ������

						std::cout << "> ";
						std::cin >> direction;

						if (direction == 'w')
						{
							if (gamemap.w_move())	//�߸��� ���� ����
							{
								std::cout << "You cannot move to that direction.\n";
								continue;
							}
							if (gamemap.check_map() == 1) break;	//Empty ĭ���� ���� ��
							else if (gamemap.check_map() == 2)		//Random ĭ���� ���� ��
							{
								std::cout << "Random encounter!\n\n";
								game_char.random_char();
								gamemap.make_empty();
								break;
							}
							else if (gamemap.check_map() == 3)	//Monster ĭ���� ���� ��
							{
								int damage;				//������
								monster_out = 0;

								Monster* game_mon = new Monster(gamemap.manhattan_dist());		//���� ����
								std::cout << "Wild monster appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//����â ���
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//���� �Է�
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//�Ϲ� ����
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//��ų �����̰� mp�� ������ ��
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//��ų ����
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//�ҼӼ� ����
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//Ǯ�Ӽ� ����
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//���Ӽ� ����
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//���� ����
									game_char.lost_hp(damage);
									std::cout << "Monster hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//ĳ���Ͱ� ������� ��
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//���Ͱ� ������� ��
									{
										std::cout << "You defeated the monster!\n";
										std::cout << "Reward: " << game_mon->show_reward() << " Gold," << game_mon->show_reward() << " EXP\n\n";
										game_char.level_up(game_mon->show_reward());
										game_char.reward_gold(game_mon->show_reward());
										delete game_mon;
										monster_out = 1;
										gamemap.make_empty();
										break;
									}

								}

							}
							else if (gamemap.check_map() == 4)	//Shop ĭ���� ���� ��
							{
								std::cout << "Welcome to the item shop!\n";
								std::cout << "You have " << game_char.show_gold() << " gold.\n";
								std::cout << "=======================================\n";
								std::cout << "============== Item list ==============\n";
								std::cout << "=======================================\n\n";
								game_shop.show_list();
								std::cout << "6. Exit shop\n\n";
								std::cout << "=======================================\n";
								while (true)
								{
									std::cout << "> ";
									std::cin >> user;

									if (user == 6)	//���� ������
									{
										shop_out = 1;
										break;
									}

									else if (user == 1 && game_shop.stock_attack() != 1)	//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 2 && game_shop.stock_defense() != 1)	//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 3 && game_shop.stock_exp() != 1)		//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else
									{
										if (user == 1 || user == 2 || user == 3)
										{
											if (game_char.show_gold() < 700)				//��� ����
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";		//������ ������ ��ǰ�� �������� ��
												if (user == 1)
												{
													game_char.attack_up(10);
													game_shop.sold_item(user);
												}
												else if (user == 2)
												{
													game_char.defense_up(5);
													game_shop.sold_item(user);
												}
												else
												{
													game_char.exp_up(300);
													game_shop.sold_item(user);
												}
												shop_out = 1;
												break;
											}
										}
										else
										{
											if (game_char.show_gold() < 500)				//��� ����
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";	//������ ������ ��ǰ�� �������� ��
												if (user == 4)
												{
													game_char.restore_hp();
													game_shop.show_list();
													std::cout << "=======================================\n\n";
												}
												else
												{
													game_char.restore_mp();
													game_shop.show_list();
													std::cout << "=======================================\n\n";
												}
												shop_out = 1;
												break;
											}
										}
									}
								}


							}
							else if (gamemap.check_map() == 5)	//Boss ĭ���� ���� ��
							{
								int damage;				//������
								monster_out = 0;

								Monster* game_mon = new Monster;		//���� ����
								std::cout << "Boss appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//����â ���
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//���� �Է�
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//�Ϲ� ����
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//��ų �����̰� mp�� ������ ��
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//��ų ����
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//�ҼӼ� ����
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//Ǯ�Ӽ� ����
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//���Ӽ� ����
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//���� ����
									game_char.lost_hp(damage);
									std::cout << "Boss hit you with " << damage << " damage!\n";

									if (game_char.show_hp() == 0)										//ĳ���Ͱ� ������� ��
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//������ ������� ��
									{
										std::cout << "You defeated the Boss!\n";
										std::cout << "Victory!";
										delete game_mon;
										monster_out = 1;
										game_over = 1;
										break;
									}

								}
							}
						}

						else if (direction == 'a')
						{
							if (gamemap.a_move())	//�߸��� ���� ����
							{
								std::cout << "You cannot move to that direction.\n";
								continue;
							}
							if (gamemap.check_map() == 1) break;	//Empty ĭ���� ���� ��
							else if (gamemap.check_map() == 2)		//Random ĭ���� ���� ��
							{
								std::cout << "Random encounter!\n\n";
								game_char.random_char();
								gamemap.make_empty();
								break;
							}
							else if (gamemap.check_map() == 3)	//Monster ĭ���� ���� ��
							{
								int damage;				//������
								monster_out = 0;

								Monster* game_mon = new Monster(gamemap.manhattan_dist());		//���� ����
								std::cout << "Wild monster appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//����â ���
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//���� �Է�
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//�Ϲ� ����
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//��ų �����̰� mp�� ������ ��
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//��ų ����
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//�ҼӼ� ����
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//Ǯ�Ӽ� ����
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//���Ӽ� ����
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//���� ����
									game_char.lost_hp(damage);
									std::cout << "Monster hit you with " << damage << " damage!\n";

									if (game_char.show_hp() == 0)										//ĳ���Ͱ� ������� ��
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//���Ͱ� ������� ��
									{
										std::cout << "You defeated the monster!\n";
										std::cout << "Reward: " << game_mon->show_reward() << " Gold," << game_mon->show_reward() << " EXP\n\n";
										game_char.level_up(game_mon->show_reward());
										game_char.reward_gold(game_mon->show_reward());
										delete game_mon;
										gamemap.make_empty();
										monster_out = 1;
										break;
									}

								}

							}
							else if (gamemap.check_map() == 4)	//Shop ĭ���� ���� ��
							{
								std::cout << "Welcome to the item shop!\n";
								std::cout << "You have " << game_char.show_gold() << " gold.\n";
								std::cout << "=======================================\n";
								std::cout << "============== Item list ==============\n";
								std::cout << "=======================================\n\n";
								game_shop.show_list();
								std::cout << "6. Exit shop\n\n";
								std::cout << "=======================================\n";
								while (true)
								{
									std::cout << "> ";
									std::cin >> user;

									if (user == 6)	//���� ������
									{
										shop_out = 1;
										break;
									}

									else if (user == 1 && game_shop.stock_attack() != 1)	//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 2 && game_shop.stock_defense() != 1)	//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 3 && game_shop.stock_exp() != 1)		//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else
									{
										if (user == 1 || user == 2 || user == 3)
										{
											if (game_char.show_gold() < 700)				//��� ����
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";		//������ ������ ��ǰ�� �������� ��
												if (user == 1)
												{
													game_char.attack_up(10);
													game_shop.sold_item(user);
												}
												else if (user == 2)
												{
													game_char.defense_up(5);
													game_shop.sold_item(user);
												}
												else
												{
													game_char.exp_up(300);
													game_shop.sold_item(user);
												}
												shop_out = 1;
												break;
											}
										}
										else
										{
											if (game_char.show_gold() < 500)				//��� ����
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";	//������ ������ ��ǰ�� �������� ��
												if (user == 4)
												{
													game_char.restore_hp();
													game_shop.show_list();
													std::cout << "=======================================\n\n";
												}
												else
												{
													game_char.restore_mp();
													game_shop.show_list();
													std::cout << "=======================================\n\n";
												}
												shop_out = 1;
												break;
											}
										}
									}
								}


							}
							else if (gamemap.check_map() == 5)	//Boss ĭ���� ���� ��
							{
								int damage;				//������
								monster_out = 0;

								Monster* game_mon = new Monster;		//���� ����
								std::cout << "Boss appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//����â ���
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//���� �Է�
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//�Ϲ� ����
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//��ų �����̰� mp�� ������ ��
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//��ų ����
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//�ҼӼ� ����
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//Ǯ�Ӽ� ����
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//���Ӽ� ����
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//���� ����
									game_char.lost_hp(damage);
									std::cout << "Boss hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//ĳ���Ͱ� ������� ��
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//������ ������� ��
									{
										std::cout << "You defeated the Boss!\n";
										std::cout << "Victory!";
										delete game_mon;
										monster_out = 1;
										game_over = 1;
										break;
									}

								}
							}
						}

						else if (direction == 's')
						{
							if (gamemap.s_move())	//�߸��� ���� ����
							{
								std::cout << "You cannot move to that direction.\n";
								continue;
							}
							if (gamemap.check_map() == 1) break;	//Empty ĭ���� ���� ��
							else if (gamemap.check_map() == 2)		//Random ĭ���� ���� ��
							{
								std::cout << "Random encounter!\n\n";
								game_char.random_char();
								gamemap.make_empty();
								break;
							}
							else if (gamemap.check_map() == 3)	//Monster ĭ���� ���� ��
							{
								int damage;				//������
								monster_out = 0;

								Monster* game_mon = new Monster(gamemap.manhattan_dist());		//���� ����
								std::cout << "Wild monster appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//����â ���
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//���� �Է�
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//�Ϲ� ����
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//��ų �����̰� mp�� ������ ��
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//��ų ����
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//�ҼӼ� ����
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//Ǯ�Ӽ� ����
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//���Ӽ� ����
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//���� ����
									game_char.lost_hp(damage);
									std::cout << "Monster hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//ĳ���Ͱ� ������� ��
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//���Ͱ� ������� ��
									{
										std::cout << "You defeated the monster!\n";
										std::cout << "Reward: " << game_mon->show_reward() << " Gold," << game_mon->show_reward() << " EXP\n\n";
										game_char.level_up(game_mon->show_reward());
										game_char.reward_gold(game_mon->show_reward());
										delete game_mon;
										gamemap.make_empty();
										monster_out = 1;
										break;
									}

								}

							}
							else if (gamemap.check_map() == 4)	//Shop ĭ���� ���� ��
							{
								std::cout << "Welcome to the item shop!\n";
								std::cout << "You have " << game_char.show_gold() << " gold.\n";
								std::cout << "=======================================\n";
								std::cout << "============== Item list ==============\n";
								std::cout << "=======================================\n\n";
								game_shop.show_list();
								std::cout << "6. Exit shop\n\n";
								std::cout << "=======================================\n";
								while (true)
								{
									std::cout << "> ";
									std::cin >> user;

									if (user == 6)	//���� ������
									{
										shop_out = 1;
										break;
									}

									else if (user == 1 && game_shop.stock_attack() != 1)	//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 2 && game_shop.stock_defense() != 1)	//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 3 && game_shop.stock_exp() != 1)		//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else
									{
										if (user == 1 || user == 2 || user == 3)
										{
											if (game_char.show_gold() < 700)				//��� ����
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";		//������ ������ ��ǰ�� �������� ��
												if (user == 1)
												{
													game_char.attack_up(10);
													game_shop.sold_item(user);
												}
												else if (user == 2)
												{
													game_char.defense_up(5);
													game_shop.sold_item(user);
												}
												else
												{
													game_char.exp_up(300);
													game_shop.sold_item(user);
												}
												shop_out = 1;
												break;
											}
										}
										else
										{
											if (game_char.show_gold() < 500)				//��� ����
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";	//������ ������ ��ǰ�� �������� ��
												if (user == 4)
												{
													game_char.restore_hp();
													game_shop.show_list();
													std::cout << "=======================================\n\n";
												}
												else
												{
													game_char.restore_mp();
													game_shop.show_list();
													std::cout << "=======================================\n\n";
												}
												shop_out = 1;
												break;
											}
										}
									}
								}


							}
							else if (gamemap.check_map() == 5)	//Boss ĭ���� ���� ��
							{
								int damage;				//������
								monster_out = 0;

								Monster* game_mon = new Monster;		//���� ����
								std::cout << "Boss appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//����â ���
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//���� �Է�
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//�Ϲ� ����
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//��ų �����̰� mp�� ������ ��
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//��ų ����
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//�ҼӼ� ����
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//Ǯ�Ӽ� ����
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//���Ӽ� ����
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//���� ����
									game_char.lost_hp(damage);
									std::cout << "Boss hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//ĳ���Ͱ� ������� ��
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//������ ������� ��
									{
										std::cout << "You defeated the Boss!\n";
										std::cout << "Victory!";
										delete game_mon;
										monster_out = 1;
										game_over = 1;
										break;
									}

								}
							}
						}

						else if (direction == 'd')
						{
							if (gamemap.d_move())
							{
								std::cout << "You cannot move to that direction.\n";
								continue;
							}
							if (gamemap.check_map() == 1) break;	//Empty ĭ���� ���� ��
							else if (gamemap.check_map() == 2)		//Random ĭ���� ���� ��
							{
								std::cout << "Random encounter!\n\n";
								game_char.random_char();
								gamemap.make_empty();
								break;
							}
							else if (gamemap.check_map() == 3)	//Monster ĭ���� ���� ��
							{
								int damage;				//������
								monster_out = 0;

								Monster* game_mon = new Monster(gamemap.manhattan_dist());		//���� ����
								std::cout << "Wild monster appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//����â ���
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//���� �Է�
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//�Ϲ� ����
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//��ų �����̰� mp�� ������ ��
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//��ų ����
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//�ҼӼ� ����
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//Ǯ�Ӽ� ����
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//���Ӽ� ����
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//���� ����
									game_char.lost_hp(damage);
									std::cout << "Monster hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//ĳ���Ͱ� ������� ��
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//���Ͱ� ������� ��
									{
										std::cout << "You defeated the monster!\n";
										std::cout << "Reward: " << game_mon->show_reward() << " Gold," << game_mon->show_reward() << " EXP\n\n";
										game_char.level_up(game_mon->show_reward());
										game_char.reward_gold(game_mon->show_reward());
										delete game_mon;
										gamemap.make_empty();
										monster_out = 1;
										break;
									}

								}

							}
							else if (gamemap.check_map() == 4)	//Shop ĭ���� ���� ��
							{
								std::cout << "Welcome to the item shop!\n";
								std::cout << "You have " << game_char.show_gold() << " gold.\n";
								std::cout << "=======================================\n";
								std::cout << "============== Item list ==============\n";
								std::cout << "=======================================\n\n";
								game_shop.show_list();
								std::cout << "6. Exit shop\n\n";
								std::cout << "=======================================\n";
								while (true)
								{
									std::cout << "> ";
									std::cin >> user;

									if (user == 6)	//���� ������
									{
										shop_out = 1;
										break;
									}

									else if (user == 1 && game_shop.stock_attack() != 1)	//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 2 && game_shop.stock_defense() != 1)	//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 3 && game_shop.stock_exp() != 1)		//��� ����
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else
									{
										if (user == 1 || user == 2 || user == 3)
										{
											if (game_char.show_gold() < 700)				//��� ����
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";		//������ ������ ��ǰ�� �������� ��
												if (user == 1)
												{
													game_char.attack_up(10);
													game_shop.sold_item(user);
												}
												else if (user == 2)
												{
													game_char.defense_up(5);
													game_shop.sold_item(user);
												}
												else
												{
													game_char.exp_up(300);
													game_shop.sold_item(user);
												}
												shop_out = 1;
												break;
											}
										}
										else
										{
											if (game_char.show_gold() < 500)				//��� ����
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";	//������ ������ ��ǰ�� �������� ��
												if (user == 4)
												{
													game_char.restore_hp();
													game_shop.show_list();
													std::cout << "=======================================\n\n";
												}
												else
												{
													game_char.restore_mp();
													game_shop.show_list();
													std::cout << "=======================================\n\n";
												}
												shop_out = 1;
												break;
											}
										}
									}
								}


							}
							else if (gamemap.check_map() == 5)	//Boss ĭ���� ���� ��
							{
								int damage;				//������
								monster_out = 0;
								std::cout << "Boss appeared!\n\n";
								Monster* game_mon = new Monster;		//���� ����
								while (true)
								{
									std::cout << "=======================================\n";	//����â ���
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//���� �Է�
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//�Ϲ� ����
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//��ų �����̰� mp�� ������ ��
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//��ų ����
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//�ҼӼ� ����
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//Ǯ�Ӽ� ����
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//���Ӽ� ����
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//���� ����
									game_char.lost_hp(damage);
									std::cout << "Boss hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//ĳ���Ͱ� ������� ��
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//������ ������� ��
									{
										std::cout << "You defeated the Boss!\n";
										std::cout << "Victory!";
										delete game_mon;
										monster_out = 1;
										game_over = 1;
										break;
									}

								}
							}
						}

						else continue;		//����
					}
				}
				else if (user == 2)			//ĳ���� ����â
				{
					game_char.show();
					std::cout << std::endl;
				}
						

				else if (user == 3)			//���� ������
				{
					exit = 1;
					break;
				}
				else continue;				//����
			}

		}
		else if (user == 2)	exit = 1;	//���� ������
		else continue;					//����
	}
	return 0;
}