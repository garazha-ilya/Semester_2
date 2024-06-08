#include "Application.h"
#include "SelectLevel/SelectState.h"

#include <iostream>

Application::Application()
    : m_ptr_state_current(std::make_unique<SelectState>(
          *this, config::SELECT_LEVEL_VIDEO_MODE, config::SELECT_LEVEL_TITLE)) {
}

int Application::run() {
  try {
    while (m_ptr_state_current->do_step())
      apply_deffer_state_change();
  } catch (std::exception &ex) {
    std::cout << ex.what() << '\n';
    return 1;
  } catch (...) {
    std::cout << "Unkonwn exception\n";
    return 2;
  }
  return 0;
}

void Application::apply_deffer_state_change() {
  if (m_ptr_state_next)
    m_ptr_state_current = std::move(m_ptr_state_next);
  m_ptr_state_next.reset();
}

void Application::set_next_state(std::unique_ptr<IState> ptr_state) {
  m_ptr_state_next = std::move(ptr_state);
}