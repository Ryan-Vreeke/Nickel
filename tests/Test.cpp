#include <gtest/gtest.h>
#include <EntityCenter.h>
#include <cstdint>
#include <glm/fwd.hpp>

TEST(EntityCenter, CreateEntityTest){
  EntityCenter ec{};
  uint32_t entity = ec.createEntity();
  uint32_t entity1 = ec.createEntity();
  uint32_t entity2 = ec.createEntity();

  ASSERT_EQ(entity, 0);
  ASSERT_EQ(entity1, 1);
  ASSERT_EQ(entity2, 2);

  ec.deleteEntity(entity1);

  uint32_t entity3 = ec.createEntity();
  ASSERT_EQ(entity3, 1);
}

TEST(EntityCenter, DoubleDeleteEntityTest){
  EntityCenter ec{};
  uint32_t entity = ec.createEntity();

  ASSERT_EQ(entity, 0);
  ASSERT_EQ(ec.entity_count, 1);

  ec.deleteEntity(entity);
  ec.deleteEntity(entity);

  ASSERT_EQ(ec.entity_count, 0);
}


TEST(EntityCenter, ComponentTest){
  EntityCenter ec{};
  uint32_t entity = ec.createEntity();

  TransformComponent transform;
  transform.pos = glm::vec3{1.0f, 1.0f, 1.0f};
  ec.transformComponents[entity] = transform;

  ASSERT_EQ(ec.transformComponents.size(), 1);
  ASSERT_EQ(ec.transformComponents[entity].pos, transform.pos);
}

// Main function for running all the tests
int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
