#pragma once
#include "Walnut/Layer.h"

#include <vector>


class NestedLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		_onUIRender();

		for (int i = 0; i < children.size(); i++)
			children[i]->OnUIRender();
	}

	virtual void OnAttach() override
	{
		_onAttach();

		for (int i = 0; i < children.size(); i++)
			children[i]->OnAttach();
	}

	virtual void OnDetach() override
	{
		_onDetach();

		for (int i = 0; i < children.size(); i++)
			delete children[i];
	}

protected:
	std::vector<Layer*> children;

	virtual void _onAttach() 	= 0;
	virtual void _onUIRender() 	= 0;
	virtual void _onDetach() 	= 0;
};