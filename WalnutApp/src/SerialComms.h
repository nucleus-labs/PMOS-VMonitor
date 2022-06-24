#pragma once
#include "serial/serial.h"

#include <iostream>

#include "NestedLayer.h"
#include "VMonitorLayer.h"


class LayerSerialInterface;

class LayerSerialInput : public Walnut::Layer
{
private:
	LayerSerialInput(serial::Serial* serial) : m_Serial(serial) {}

	void OnAttach() override;

	void OnUIRender() override {}

	serial::Serial* m_Serial;

	friend class LayerSerialInterface;
};


class LayerSerialOutput : public Walnut::Layer
{
private:
	LayerSerialOutput(serial::Serial* serial) : m_Serial(serial) {}

	void OnAttach() override
	{
		std::cout << "LayerSerialOutput attached!" << std::endl;
	}

    void OnUIRender() override;

	serial::Serial* m_Serial;

	friend class LayerSerialInterface;
};


class LayerSerialInterface : public NestedLayer
{
public:
	LayerSerialInterface(serial::Serial* serial, LayerVirtualMonitor* vmonitor)
		: m_Serial(serial), m_VMonitor(vmonitor)
	{
		std::cout << "foo" << std::endl;
	}

	virtual void _onAttach() override
	{
		children.push_back(new LayerSerialInput(m_Serial));
		children.push_back(new LayerSerialOutput(m_Serial));
		std::cout << "LayerSerialInterface attached!" << std::endl;
	}

	void _onUIRender() override {}

	virtual void _onDetach() override
	{
		delete m_Serial;
	}

private:
	serial::Serial* m_Serial;
	LayerVirtualMonitor* m_VMonitor;
};