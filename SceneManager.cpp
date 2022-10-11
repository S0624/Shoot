#include"SceneManager.h"
#include"SceneTitle.h"

SceneManager::SceneManager()
{
	m_kind = kSceneKindTitle;			//シーンの種類
	m_pScene = nullptr;
}


void SceneManager::init(SceneKind kind )
{
	m_pScene = new SceneTitle;
	m_pScene->init();
}

void SceneManager::end()
{
	if (!m_pScene) return;

	m_pScene->end();
	delete m_pScene;
}

void SceneManager::update()
{
	if (!m_pScene) return;

	SceneBase* pScene = m_pScene->update();		//nullでなければupdate処理を行う
	if (pScene != m_pScene)
	{
		//前のシーンの終了処理
		m_pScene->end();
		delete m_pScene;

		m_pScene = pScene;
		m_pScene->init();
	}
}

void SceneManager::draw()
{
	if (!m_pScene) return;

	m_pScene->draw();		//nullでなければupdate処理を行う
}