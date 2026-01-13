#include <rclcpp/rclcpp.hpp>

class HelloNode : public rclcpp::Node
{
public:
  HelloNode() : Node("hello_world_node")
  {
    RCLCPP_INFO(this->get_logger(), "Hello, World!");
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin_some(std::make_shared<HelloNode>());
  rclcpp::shutdown();
  return 0;
}

