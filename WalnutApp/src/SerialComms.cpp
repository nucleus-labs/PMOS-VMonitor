#include "SerialComms.h"

void LayerSerialInput::OnAttach()
{
    std::cout << "LayerSerialInput attached!" << std::endl;

    std::cout << "Is the serial port open? ";

    if (m_Serial->isOpen())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    if (m_Serial->isOpen())
    {
        m_Serial->write("Hello World!");
    }
}

void LayerSerialOutput::OnUIRender()
{
    if (m_Serial->isOpen())
    {
        size_t bytes = m_Serial->available();
        std::string data;
        if (bytes > 0)
        {
            data = m_Serial->read(bytes);
            std::cout << data << std::endl;
        }
    }
}