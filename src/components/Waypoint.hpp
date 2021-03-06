#pragma once
#include <BsPrerequisites.h>
#include <Scene/BsComponent.h>
#include <RTTI/RTTIUtil.hpp>

namespace REGoth
{
  class Waypoint;
  using HWaypoint = bs::GameObjectHandle<Waypoint>;

  /**
   * See Waynet.
   *
   * Waypoints don't do much other than being invisible
   * and having a name you can search for and having a list of waypoints this one
   * is connected to.
   */
  class Waypoint : public bs::Component
  {
  public:
    Waypoint(const bs::HSceneObject& parent);

    /**
     * Adds a path from this waypoint to the given one.
     */
    void addPathTo(HWaypoint waypoint);

    /**
     * @return All paths from this waypoint.
     */
    const bs::Vector<HWaypoint> allPaths() const
    {
      return mPaths;
    }

  private:

    friend class Waynet;

    /**
     * Index only valid to the Waynet-component. This is the index this Waypoint
     * has into the acceleration data structures of the Waynet. Should not be set
     * other than during Waynet::addWaypoint().
     */
    bs::UINT32 mIndex = 0;

    /**
     * Other waypoint this one is connected to.
     */
    bs::Vector<HWaypoint> mPaths;

  public:
    REGOTH_DECLARE_RTTI(Waypoint)

  protected:
    Waypoint() = default; // For RTTI
  };
}
