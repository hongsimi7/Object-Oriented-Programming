#include <iostream>
#include "map.h"
#include "character.h"
#include "monster.h"
#include "shop.h"
#include <cstdlib>

int main()
{
	int user;				//유저 입력
	int exit = 0;			//나가기 신호
	char direction;			//유저 방향 입력
	int game_over = 0;		//유저 사망 신호
	int monster_out = 0;	//몬스터 사망 신호
	int shop_out = 0;		//상점 나가기 신호

	std::cout << "========================================================" << std::endl;				//초기 화면
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
		if (exit == 1)				//게임 나가기
		{
			std::cout << "Exit...";
			break;
		}
		if (game_over == 1)  break;	//게임오버

		std::cout << "> ";
		std::cin >> user;

		if (user == 1)			//게임 시작
		{
			std::cout << "Game start!" << std::endl << std::endl;
			Map gamemap;					//맵생성
			Character game_char;			//캐릭터 생성
			Shop game_shop;					//상점 생성

			while (true)
			{
				if (game_over == 1) break; //게임 나가기
				monster_out = 0;
				shop_out = 0;

				gamemap.show();
				std::cout << "1. Choose direction\n";
				std::cout << "2. Show character status\n";
				std::cout << "3. Exit game\n";
				std::cout << "> ";
				std::cin >> user;

				if (user == 1)				//방향 선택
				{
					std::cout << "Where do you want to go?\n";

					while (true)
					{
						if (game_over == 1 || monster_out == 1 || shop_out == 1) break;		//게임 나가기

						std::cout << "> ";
						std::cin >> direction;

						if (direction == 'w')
						{
							if (gamemap.w_move())	//잘못된 방향 선택
							{
								std::cout << "You cannot move to that direction.\n";
								continue;
							}
							if (gamemap.check_map() == 1) break;	//Empty 칸으로 갔을 때
							else if (gamemap.check_map() == 2)		//Random 칸으로 갔을 때
							{
								std::cout << "Random encounter!\n\n";
								game_char.random_char();
								gamemap.make_empty();
								break;
							}
							else if (gamemap.check_map() == 3)	//Monster 칸으로 갔을 때
							{
								int damage;				//데미지
								monster_out = 0;

								Monster* game_mon = new Monster(gamemap.manhattan_dist());		//몬스터 생성
								std::cout << "Wild monster appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//상태창 출력
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//공격 입력
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//일반 공격
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//스킬 공격이고 mp가 부족할 때
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//스킬 공격
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//불속성 공격
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//풀속성 공격
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//물속성 공격
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//몬스터 공격
									game_char.lost_hp(damage);
									std::cout << "Monster hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//캐릭터가 사망했을 때
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//몬스터가 사망했을 때
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
							else if (gamemap.check_map() == 4)	//Shop 칸으로 갔을 때
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

									if (user == 6)	//상점 나가기
									{
										shop_out = 1;
										break;
									}

									else if (user == 1 && game_shop.stock_attack() != 1)	//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 2 && game_shop.stock_defense() != 1)	//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 3 && game_shop.stock_exp() != 1)		//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else
									{
										if (user == 1 || user == 2 || user == 3)
										{
											if (game_char.show_gold() < 700)				//골드 부족
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";		//수량이 정해진 물품을 구매했을 때
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
											if (game_char.show_gold() < 500)				//골드 부족
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";	//수량이 무한이 물품을 구매했을 때
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
							else if (gamemap.check_map() == 5)	//Boss 칸으로 갔을 때
							{
								int damage;				//데미지
								monster_out = 0;

								Monster* game_mon = new Monster;		//보스 생성
								std::cout << "Boss appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//상태창 출력
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//공격 입력
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//일반 공격
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//스킬 공격이고 mp가 부족할 때
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//스킬 공격
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//불속성 공격
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//풀속성 공격
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//물속성 공격
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//보스 공격
									game_char.lost_hp(damage);
									std::cout << "Boss hit you with " << damage << " damage!\n";

									if (game_char.show_hp() == 0)										//캐릭터가 사망했을 때
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//보스가 사망했을 때
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
							if (gamemap.a_move())	//잘못된 방향 선택
							{
								std::cout << "You cannot move to that direction.\n";
								continue;
							}
							if (gamemap.check_map() == 1) break;	//Empty 칸으로 갔을 때
							else if (gamemap.check_map() == 2)		//Random 칸으로 갔을 때
							{
								std::cout << "Random encounter!\n\n";
								game_char.random_char();
								gamemap.make_empty();
								break;
							}
							else if (gamemap.check_map() == 3)	//Monster 칸으로 갔을 때
							{
								int damage;				//데미지
								monster_out = 0;

								Monster* game_mon = new Monster(gamemap.manhattan_dist());		//몬스터 생성
								std::cout << "Wild monster appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//상태창 출력
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//공격 입력
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//일반 공격
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//스킬 공격이고 mp가 부족할 때
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//스킬 공격
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//불속성 공격
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//풀속성 공격
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//물속성 공격
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//몬스터 공격
									game_char.lost_hp(damage);
									std::cout << "Monster hit you with " << damage << " damage!\n";

									if (game_char.show_hp() == 0)										//캐릭터가 사망했을 때
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//몬스터가 사망했을 때
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
							else if (gamemap.check_map() == 4)	//Shop 칸으로 갔을 때
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

									if (user == 6)	//상점 나가기
									{
										shop_out = 1;
										break;
									}

									else if (user == 1 && game_shop.stock_attack() != 1)	//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 2 && game_shop.stock_defense() != 1)	//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 3 && game_shop.stock_exp() != 1)		//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else
									{
										if (user == 1 || user == 2 || user == 3)
										{
											if (game_char.show_gold() < 700)				//골드 부족
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";		//수량이 정해진 물품을 구매했을 때
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
											if (game_char.show_gold() < 500)				//골드 부족
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";	//수량이 무한이 물품을 구매했을 때
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
							else if (gamemap.check_map() == 5)	//Boss 칸으로 갔을 때
							{
								int damage;				//데미지
								monster_out = 0;

								Monster* game_mon = new Monster;		//보스 생성
								std::cout << "Boss appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//상태창 출력
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//공격 입력
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//일반 공격
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//스킬 공격이고 mp가 부족할 때
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//스킬 공격
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//불속성 공격
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//풀속성 공격
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//물속성 공격
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//보스 공격
									game_char.lost_hp(damage);
									std::cout << "Boss hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//캐릭터가 사망했을 때
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//보스가 사망했을 때
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
							if (gamemap.s_move())	//잘못된 방향 선택
							{
								std::cout << "You cannot move to that direction.\n";
								continue;
							}
							if (gamemap.check_map() == 1) break;	//Empty 칸으로 갔을 때
							else if (gamemap.check_map() == 2)		//Random 칸으로 갔을 때
							{
								std::cout << "Random encounter!\n\n";
								game_char.random_char();
								gamemap.make_empty();
								break;
							}
							else if (gamemap.check_map() == 3)	//Monster 칸으로 갔을 때
							{
								int damage;				//데미지
								monster_out = 0;

								Monster* game_mon = new Monster(gamemap.manhattan_dist());		//몬스터 생성
								std::cout << "Wild monster appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//상태창 출력
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//공격 입력
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//일반 공격
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//스킬 공격이고 mp가 부족할 때
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//스킬 공격
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//불속성 공격
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//풀속성 공격
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//물속성 공격
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//몬스터 공격
									game_char.lost_hp(damage);
									std::cout << "Monster hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//캐릭터가 사망했을 때
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//몬스터가 사망했을 때
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
							else if (gamemap.check_map() == 4)	//Shop 칸으로 갔을 때
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

									if (user == 6)	//상점 나가기
									{
										shop_out = 1;
										break;
									}

									else if (user == 1 && game_shop.stock_attack() != 1)	//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 2 && game_shop.stock_defense() != 1)	//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 3 && game_shop.stock_exp() != 1)		//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else
									{
										if (user == 1 || user == 2 || user == 3)
										{
											if (game_char.show_gold() < 700)				//골드 부족
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";		//수량이 정해진 물품을 구매했을 때
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
											if (game_char.show_gold() < 500)				//골드 부족
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";	//수량이 무한이 물품을 구매했을 때
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
							else if (gamemap.check_map() == 5)	//Boss 칸으로 갔을 때
							{
								int damage;				//데미지
								monster_out = 0;

								Monster* game_mon = new Monster;		//보스 생성
								std::cout << "Boss appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//상태창 출력
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//공격 입력
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//일반 공격
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//스킬 공격이고 mp가 부족할 때
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//스킬 공격
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//불속성 공격
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//풀속성 공격
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//물속성 공격
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//보스 공격
									game_char.lost_hp(damage);
									std::cout << "Boss hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//캐릭터가 사망했을 때
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//보스가 사망했을 때
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
							if (gamemap.check_map() == 1) break;	//Empty 칸으로 갔을 때
							else if (gamemap.check_map() == 2)		//Random 칸으로 갔을 때
							{
								std::cout << "Random encounter!\n\n";
								game_char.random_char();
								gamemap.make_empty();
								break;
							}
							else if (gamemap.check_map() == 3)	//Monster 칸으로 갔을 때
							{
								int damage;				//데미지
								monster_out = 0;

								Monster* game_mon = new Monster(gamemap.manhattan_dist());		//몬스터 생성
								std::cout << "Wild monster appeared!\n\n";
								while (true)
								{
									std::cout << "=======================================\n";	//상태창 출력
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//공격 입력
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//일반 공격
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//스킬 공격이고 mp가 부족할 때
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//스킬 공격
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//불속성 공격
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//풀속성 공격
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//물속성 공격
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the monster with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//몬스터 공격
									game_char.lost_hp(damage);
									std::cout << "Monster hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//캐릭터가 사망했을 때
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//몬스터가 사망했을 때
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
							else if (gamemap.check_map() == 4)	//Shop 칸으로 갔을 때
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

									if (user == 6)	//상점 나가기
									{
										shop_out = 1;
										break;
									}

									else if (user == 1 && game_shop.stock_attack() != 1)	//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 2 && game_shop.stock_defense() != 1)	//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else if (user == 3 && game_shop.stock_exp() != 1)		//재고 부족
									{
										std::cout << "Selected item is not available...\n\n";
										continue;
									}
									else
									{
										if (user == 1 || user == 2 || user == 3)
										{
											if (game_char.show_gold() < 700)				//골드 부족
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";		//수량이 정해진 물품을 구매했을 때
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
											if (game_char.show_gold() < 500)				//골드 부족
											{
												std::cout << "You do not have enough gold...\n\n";
												continue;
											}
											else
											{
												std::cout << "You bought an item!\n\n";	//수량이 무한이 물품을 구매했을 때
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
							else if (gamemap.check_map() == 5)	//Boss 칸으로 갔을 때
							{
								int damage;				//데미지
								monster_out = 0;
								std::cout << "Boss appeared!\n\n";
								Monster* game_mon = new Monster;		//보스 생성
								while (true)
								{
									std::cout << "=======================================\n";	//상태창 출력
									std::cout << "Character status";
									game_char.show();
									std::cout << "=======================================\n";
									game_mon->show();
									std::cout << "=======================================\n";

									while (true)
									{
										std::cout << "Choose your action\n";					//공격 입력
										std::cout << "1. Meele attack\n";
										std::cout << "2. Magic attack\n";
										std::cout << "3. Fire magic attack\n";
										std::cout << "4. Grass magic attack\n";
										std::cout << "5. Water magic attack\n";
										std::cout << "> ";
										std::cin >> user;

										if (user == 1)		//일반 공격
										{
											damage = game_char.attack_basic(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (game_char.show_mp() < 15)	//스킬 공격이고 mp가 부족할 때
										{
											std::cout << "Not enough MP...\n";
											break;
										}
										else if (user == 2)	//스킬 공격
										{
											damage = game_char.attack_skill(game_mon->show_defense());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 3)	//불속성 공격
										{
											damage = game_char.attack_fire(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 4)	//풀속성 공격
										{
											damage = game_char.attack_grass(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else if (user == 5)	//물속성 공격
										{
											damage = game_char.attack_water(game_mon->show_defense(), game_mon->show_type());
											game_mon->lost_hp(damage);
											std::cout << "\nYou hit the boss with " << damage << " damage!\n";
											break;
										}
										else continue;
									}
									damage = game_mon->monster_attack(game_char.show_defense());		//보스 공격
									game_char.lost_hp(damage);
									std::cout << "Boss hit you with " << damage << " damage!\n\n";

									if (game_char.show_hp() == 0)										//캐릭터가 사망했을 때
									{
										std::cout << "\nYou died...";
										game_over = 1;
										break;
									}
									else if (game_mon->show_hp() == 0)									//보스가 사망했을 때
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

						else continue;		//오류
					}
				}
				else if (user == 2)			//캐릭터 상태창
				{
					game_char.show();
					std::cout << std::endl;
				}
						

				else if (user == 3)			//게임 나가기
				{
					exit = 1;
					break;
				}
				else continue;				//오류
			}

		}
		else if (user == 2)	exit = 1;	//게임 나가기
		else continue;					//오류
	}
	return 0;
}