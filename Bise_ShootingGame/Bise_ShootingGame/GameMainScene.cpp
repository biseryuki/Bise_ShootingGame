#include "GameMainScene.h"
#include "Recovery.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


GameMainScene::GameMainScene()
{
	T_Location location = T_Location{ 20,100 };
	player = new Player(location);

	enemy = new Enemy * [10];
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}
	/*enemy[0] = new Enemy(T_Location{ 200,0 });*/
	enemy[0] = new Enemy(T_Location{ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });

	items = new ItemBase * [10];
	for (int i = 0; i < 10; i++)
	{
		items[i] = nullptr;
	}
}

//�`��ȊO�̍X�V����������
void GameMainScene::Update()
{
	player->Update();

	int enemyCount;
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Update();
	}

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Update();
	}

	BulletsBase** bullet = player->GetBullets();
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		for (int bulletCount = 0; bulletCount < 30; bulletCount++)
		{
			if (bullet[bulletCount] == nullptr)
			{
				break;
			}

			if (enemy[enemyCount]->HitSphere(bullet[bulletCount]))
			{
				//�G�l�~�[�ƃv���C���[�̒e���q�b�g���Ă���

				//�G�l�~�[�Ƀ_���[�W��^���܂�
				enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());

				//�e���������܂�
				player->DeleteBullet(bulletCount);
				bulletCount--;

				//�G�l�~�[��HP��0�ȉ���������A�G�l�~�[���폜���܂��B

				if (enemy[enemyCount]->HpCheck())
				{
					for (int i = 0; i < 10; i++)
					{
						if (items[i] == nullptr)
						{
							items[i] = new Recovery(enemy[enemyCount]->GetLocation());
							break;
						}
					}

					//�X�R�A�̉��Z
					player->AddScore(enemy[enemyCount]->GetPoint());

					//�G�l�~�[�̍폜
					delete enemy[enemyCount];
					enemy[enemyCount] = nullptr;

					//�z���O�ɋl�߂�
					for (int i = enemyCount; i < (10 - 1); i++)
					{
						if (enemy[i + 1] == nullptr)
						{
							break;
						}
						enemy[i] = enemy[i + 1];
						enemy[i + 1] = nullptr;
					}
					enemyCount--;
					break;
				}
			}
		}
	}

	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (items[itemCount] == nullptr)
		{
			break;
		}
		if (items[itemCount]->HitSphere(player) == true)
		{
			//�񕜏���
			player->Hit(items[itemCount]);

			delete items[itemCount];
			items[itemCount] = nullptr;

			//�z���O�ɋl�߂�
			for (int i = itemCount + 1; i < 10; i++)
			{
				if (items[i] == nullptr)
				{
					break;
				}
				items[i - 1] = items[i];
				items[i] = nullptr;
			}
			itemCount--;
			break;
		}
	}

	//�G�̒e���Ƃ��Ă���
	for (enemyCount=0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		bullet = enemy[enemyCount]->GetBullets();
	//for(�e�����[�v�ŎQ��){
		for (int i = 0; i < 30; i++)
		{
			if (bullet[i] == nullptr)
			{
				break;
			}
			
	// 	   if(�G�̒e�ƃv���C���[�̓����蔻��)�@{
	//			�v���C���[�Ƀ_���[�W��^����
			if (player->HitSphere(bullet[i]))
			{
				player->Hit(bullet[i]->GetDamage());

				enemy[enemyCount]->DeleteBullet(i);
				i--;
			}
		}
	}

	// 
	//			�G�̒e���폜����
	// 	   }
	// }
	//
}

//�`��Ɋւ��邱�Ƃ���������
void GameMainScene::Draw() const
{
	player->Draw();

	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Draw();
	}

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Draw();
	}

}

//�V�[���̕ύX����
AbstractScene* GameMainScene::ChangeScene()
{
	return this;
}