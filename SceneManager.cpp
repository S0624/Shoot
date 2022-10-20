#include"SceneManager.h"

#include <cassert>

SceneManager::SceneManager()
{
	m_kind = kSceneKindTitle;			//シーンの種類
	m_kind = kSceneKindMain;			//シーンの種類
	m_kind = kSceneKindResultLose;			//シーンの種類
}


void SceneManager::init(SceneKind kind )
{
	m_kind = kind;
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.init();
		break;
	case SceneManager::kSceneKindMain:
		m_main.init();
		break;
	case SceneManager::kSceneKindResultLose:
		m_lose.init();
		break;
	default:
		assert(false);
		break;
	}
}

void SceneManager::end()
{
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.end();
		break;
	case SceneManager::kSceneKindMain:
		m_main.end();
		break;
	case SceneManager::kSceneKindResultLose:
		m_lose.end();
		break;
	default:
		assert(false);
		break;
	}
}

void SceneManager::update()
{
	bool isEnd = false;
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.update();
		isEnd = m_title.isEnd();
		break;
	case SceneManager::kSceneKindMain:
		m_main.update();
		isEnd = m_main.isEnd();
		break;
	case SceneManager::kSceneKindResultLose:
		m_lose.update();
		isEnd = m_lose.isEnd();
		break;
	default:
		assert(false);
		break;
	}
	if (isEnd)
	{
		switch (m_kind)
		{
		case SceneManager::kSceneKindTitle:
			m_title.end();
			m_main.init();
			m_kind = kSceneKindMain;
			break;
		case SceneManager::kSceneKindMain:
			m_main.end();
			m_lose.init();
			m_kind = kSceneKindResultLose;
			break;
		case SceneManager::kSceneKindResultLose:
			m_lose.end();
			break;
		default:
			assert(false);
			break;
		}
	}
}

void SceneManager::draw()
{
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.draw();
		break;
	case SceneManager::kSceneKindMain:
		m_main.draw();
		break;
	case SceneManager::kSceneKindResultLose:
		m_lose.draw();
		break;
	default:
		assert(false);
		break;
	}
}