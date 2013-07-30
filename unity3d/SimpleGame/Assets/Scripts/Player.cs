using UnityEngine;
using System.Collections;

public class Player : MonoBehaviour
{
    enum State { Playing, Explosion, Invincible }

    private const float ShipInvisibleTime = 1.5f;
    private const float ShipMoveOnToScreenSpeed = 5f;
    private const float BlinkRate = 0.1f;
    private const int NumOfTimesToBlink = 10;

    public static int Score = 0;
    public static int Lives = 3;
    public static int Missed = 0;

    public float PlayerSpeed;
    public GameObject ProjectilePrefab;
    public GameObject ExplosionPrefab;

    private State _state = State.Playing;
    private int _blinkCount;

	// Update is called once per frame
	void Update()
	{
        // do nothing if exploding
	    if (_state == State.Explosion) return;

	    // Amount to move 
	    var amountToMove = Input.GetAxisRaw("Horizontal")*PlayerSpeed*Time.deltaTime;

	    // Move the player
	    transform.Translate(Vector3.right*amountToMove);

	    // Screen wrap checking
	    if (transform.position.x <= -7.4f || transform.position.x >= 7.4f)
	        transform.position = new Vector3(-transform.position.x, transform.position.y,
	                                         transform.position.z);

	    // Fire projectile
	    if (Input.GetKeyDown("space"))
	    {
	        var firePosition = new Vector3(transform.position.x,
	                                       transform.position.y + (transform.localScale.y/2),
	                                       transform.position.z);

	        Instantiate(ProjectilePrefab, firePosition, Quaternion.identity);
	    }
	}

    void OnGUI()
    {
        GUI.Label(new Rect(10, 10, 120, 20), string.Format("Score: {0}", Player.Score));
        GUI.Label(new Rect(10, 30, 120, 20), string.Format("Lives: {0}", Player.Lives));
        GUI.Label(new Rect(10, 50, 120, 20), string.Format("Misses: {0}", Player.Missed));
    }

    void OnTriggerEnter(Collider other)
    {
        // can only get hit while 'playing'
        if (_state != State.Playing) return;

        if (other.tag == "Enemy")
        {
            Player.Lives--;
            
            var enemy = (Enemy) other.gameObject.GetComponent("Enemy");
            enemy.Spawn();

            StartCoroutine(DestroyShip());
        }
    }

    IEnumerator DestroyShip()
    {
        _state = State.Explosion;
        Instantiate(ExplosionPrefab, transform.position, Quaternion.identity);

        gameObject.renderer.enabled = false;
        transform.position = new Vector3(0f, -5, transform.position.z);
        yield return new WaitForSeconds(ShipInvisibleTime);

        if (Player.Lives > 0)
        {
            gameObject.renderer.enabled = true;

            while (transform.position.y < -3.2f)
            {
                var amountToMove = ShipMoveOnToScreenSpeed * Time.deltaTime;
                transform.position = new Vector3(0f, transform.position.y + amountToMove,
                                                 transform.position.z);

                yield return 0;
            }

            _state = State.Invincible;

            _blinkCount = 0;
            while (_blinkCount < NumOfTimesToBlink)
            {
                gameObject.renderer.enabled = !gameObject.renderer.enabled;
                if (gameObject.renderer.enabled)
                    _blinkCount++;

                yield return new WaitForSeconds(BlinkRate);
            }

            _state = State.Playing;
        }
        else
        {
            Application.LoadLevel(2);
        }
    }
}