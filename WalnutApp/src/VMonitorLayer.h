#pragma once
#include "Walnut/Layer.h"
#include "Walnut/Image.h"

#include <vector>


class LayerVirtualMonitor : public Walnut::Layer
{
public:
	LayerVirtualMonitor(uint32_t width, uint32_t height, uint8_t buffer_count = 2)
		: m_Width(width), m_Height(height), m_BufferCount(buffer_count)
	{
		m_DisplayBuffers = new (uint8_t*)[m_BufferCount];
		for (uint8_t i = 0; i < m_BufferCount; i++)
			m_DisplayBuffers[i] = new uint8_t[m_Width * m_Height * 4];
	}

	virtual void OnUIRender() override
	{

	}

	virtual void OnDetach()
	{
		for (uint8_t i = 0; i < m_BufferCount; i++)
			delete[] m_DisplayBuffers[i];
		delete[] m_DisplayBuffers;
	}

	void EnqueueInstruction(const uint8_t[] instruction)
	{

	}

private:
	uint32_t m_Width, m_Height;

	uint8_t** m_DisplayBuffers;
	uint8_t** m_InstructionQueue;

	uint8_t m_BufferCount;
	uint8_t drawCount = 0;
};