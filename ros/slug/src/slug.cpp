#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  
  auto node = rclcpp::Node::make_shared("Slug");

  RCLCPP_INFO(node->get_logger(), "Get ooorrff moi Brassicas!!!");

  rclcpp::shutdown();
  return 0;
}
