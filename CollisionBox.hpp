#pragma once

#include "Inivar.hpp"
#include "PlayerStats.hpp"

class CollisionBox {
public: 
	CollisionBox() {}
	CollisionBox(const glm::vec2& p, const glm::vec2& s, const bool i, std::string n = "")
		: pos(p), size(s), is_trigger(i), name(n) {
		UpdateBoxCoord();
	}
	virtual ~CollisionBox() {}

	inline void SetPos(const glm::vec2& p) { pos = p; UpdateBoxCoord(); }
	inline void SetSize(const glm::vec2& s) { size = s; UpdateBoxCoord(); }
	inline void SetTrigger(const bool i) { is_trigger = i; }
	inline glm::vec4 GetBoxCoord() const { return box_coord; }
	inline bool IsTrigger() const { return is_trigger; }

	virtual void OnCollisionEnter(std::shared_ptr<CollisionBox> cb) {}
	virtual void OnTriggerEnter(std::shared_ptr<CollisionBox> cb) {}

	std::string name;

private:
	glm::vec2 pos {0};
	glm::vec2 size {0};
	glm::vec4 box_coord {0};
	bool is_trigger = false;

	void UpdateBoxCoord();
};

class BlockCollisionBox : public CollisionBox {
public:
	using CollisionBox::CollisionBox;
	~BlockCollisionBox() {}
};

class PlayerCollisionBox : public CollisionBox {
public:	
	using CollisionBox::CollisionBox;
	~PlayerCollisionBox() {}

	//std::shared_ptr<PlayerObject> ownerPlayer;

private:
	// A player pointer to do game logic.
	
};

class ThornCollisionBox : public CollisionBox {
public:
	using CollisionBox::CollisionBox;
	void OnTriggerEnter(std::shared_ptr<CollisionBox> cb) override;
	~ThornCollisionBox() {}
private:
	
};