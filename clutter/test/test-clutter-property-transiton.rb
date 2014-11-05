# Copyright (C) 2014  Ruby-GNOME2 Project Team
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

class ClutterPropertyTransition < Test::Unit::TestCase
  include ClutterTestUtils

  def setup
    @transition = Clutter::PropertyTransition.new
  end

  def test_property_name_accessors
    only_clutter_version(1, 10, 0)
    name = "clutter property"
    @transition.property_name = name
    assert_equal(name, @transition.property_name)
  end
end
