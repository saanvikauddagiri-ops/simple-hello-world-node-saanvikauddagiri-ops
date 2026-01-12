#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class HelloNode : public rclcpp::Node
{
public:
  HelloNode() : Node("hello_world_node")
  {
    timer_ = this->create_wall_timer(
      1000ms,
      [this]() {
        RCLCPP_INFO(this->get_logger(), "Hello, World!");
      }
    );
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloNode>());
  rclcpp::shutdown();
  return 0;
}
