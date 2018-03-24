#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "Vector3.hpp"
#include "SheetSprite.hpp"

class SheetSprite;
class ShaderProgram;
class Matrix;

enum EntityType {
    ENTITY_PLAYER,
    ENTITY_ENEMY
};

class Entity {
public:
    Entity();
    Entity(float x, float y, float width, float height, EntityType type);
    Entity(float x, float y, SheetSprite *sprite, EntityType type);
    
    void Update(float elapsed);
    void Render(ShaderProgram& program, Matrix& modelMatrix) const;
    bool CollidesWith(const Entity& other);
    bool CollidesWith(float x, float y, float width, float height);
    void SetSprite(SheetSprite* newSprite);
    
    SheetSprite* sprite;
    
    Vector3 position;
    Vector3 size;
    Vector3 velocity;
    Vector3 acceleration;
    
    float rotation = 0.0f;
    
    EntityType entityType;
    
    bool collidedTop;
    bool collidedBottom;
    bool collidedLeft;
    bool collidedRight;
};
#endif
