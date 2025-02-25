// src/Application/ApplicationManager.cpp
#include "ApplicationManager.h"

ApplicationManager::ApplicationManager(IApplication* application): m_Application(application)
{
}


void ApplicationManager::init()
{
    m_Window = new Window();
    m_Application->setWindow(m_Window);
    m_Window->init();

    m_ImguiWindow = new ImguiWindow();
    m_Application->setImguiWindow(m_ImguiWindow);
    m_ImguiWindow->init(m_Window);

    m_Application->init();
}

void ApplicationManager::update()
{
    while (m_Running)
    {
        if (glfwWindowShouldClose(m_Window->getWindow()))
        {
            m_Running = false;
        }
        const float deltaTime = m_ImguiWindow->getIO()->DeltaTime;

        m_Window->updateStart();

        m_ImguiWindow->updateStart();

        m_Application->onUpdate(deltaTime);

        m_Application->onImguiUpdate(deltaTime);

        m_ImguiWindow->updateEnd();

        m_Window->updateEnd();
    }
}

void ApplicationManager::shutdown() const
{
    m_Application->shutdown();
    ImguiWindow::shutdown();
    m_Window->shutdown();

    delete m_Application;
    delete m_ImguiWindow;
    delete m_Window;
}
