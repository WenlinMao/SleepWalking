#pragma once

#include "Inivar.hpp"

class CollisionBox {
public: 
	CollisionBox();
	CollisionBox(const glm::vec2& p, const glm::vec2& s, const bool i)
		: pos(p), size(s), is_trigger(i) {
		UpdateBoxCoord();
	}
	~CollisionBox();

	inline void SetPos(const glm::vec2& p) { pos = p; UpdateBoxCoord(); }
	inline void SetSize(const glm::vec2& s) { size = s; UpdateBoxCoord(); }
	inline void SetTrigger(const bool i) { is_trigger = i; }
	inline glm::vec4 GetBoxCoord() const { return box_coord; }
	inline bool IsTrigger() const { return is_trigger; }

	virtual void OnCollisionEnter(std::shared_ptr<CollisionBox> cb) {}
	virtual void OnTriggerEnter(std::shared_ptr<CollisionBox> cb) {}

private:
	glm::vec2 pos {0};
	glm::vec2 size {0};
	glm::vec4 box_coord {0};
	bool is_trigger = false;

	void UpdateBoxCoord();
};

class PlayerCollisionBox : CollisionBox {
public:	

private:
	// A player pointer to do game logic.
	// std::shared_ptr<Player>
};

class ThornCollisionBox : CollisionBox {
public:
	void OnTriggerEnter(std::shared_ptr<CollisionBox> cb) override;

private:
	
};