#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
//#include "Walnut/Image.h"

#include "VMonitorLayer.h"
#include "SerialComms.h"
#include "NestedLayer.h"


class LayerNestedVMonitorGroup : public NestedLayer
{
	void _onAttach() override
	{
		LayerVirtualMonitor* vmonitor = new LayerVirtualMonitor(640, 480);
		LayerSerialInterface* serial_interface = new LayerSerialInterface(
			new serial::Serial(
				"com10", 9600,
				serial::Timeout::simpleTimeout(1000),
				serial::eightbits, serial::parity_none,
				serial::stopbits_one, serial::flowcontrol_none,
				serial::dtr_enable
			),
			vmonitor
		);

		children.push_back(serial_interface);
		children.push_back(vmonitor);

		std::cout << "test" << std::endl;
	}

	void _onUIRender() override {}
};


Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "PMOS Virtual Monitor";
	spec.Width = 640;
	spec.Height = 480;

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<LayerNestedVMonitorGroup>();
	return app;
}